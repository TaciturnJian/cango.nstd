import re
import sys
from pathlib import Path
from typing import List, Optional

def scan_hpp_files(directory: str) -> List[Path]:
    path = Path(directory)
    if not path.exists():
        print(f"错误: 目录 '{directory}' 不存在")
        return []

    if not path.is_dir():
        print(f"错误: '{directory}' 不是目录")
        return []

    # 递归扫描所有.hpp文件
    hpp_files = list(path.rglob("*.hpp"))

    print(f"找到 {len(hpp_files)} 个.hpp文件")
    return hpp_files

def extract_namespace_content(file_path: Path) -> Optional[str]:
    content = file_path.read_text(encoding='utf-8')
    namespace_pos = content.find('namespace')
    if namespace_pos == -1:
        print("[warn] 在文件({})中找不到 namespace".format(file_path))
        return None
    namespace_pos += 9

    first_left_brace_pos = content.find('{', namespace_pos)
    if first_left_brace_pos == -1:
        print("[warn] 在文件({})中找不到一个左括号".format(file_path))
    first_left_brace_pos += 1

    last_right_brace_pos = content.find('}', namespace_pos)
    if last_right_brace_pos == -1:
        print("[warn] 在文件({})中找不到一个右括号".format(file_path))
    last_right_brace_pos -= 1

    left_brace_pos = first_left_brace_pos
    while True:
        mid_left_brace_pos = content.find('{', left_brace_pos)
        if mid_left_brace_pos == -1:
            return content[first_left_brace_pos:last_right_brace_pos]
        left_brace_pos = mid_left_brace_pos + 1
        last_right_brace_pos = content.find('}', last_right_brace_pos + 2)
        if last_right_brace_pos == -1:
            print("[warn] 文件({})的左右括号不匹配".format(file_path))
            return None
        last_right_brace_pos -= 1

def create_ixx_file(hpp_file: Path, namespace_content: str) -> None:
    # 获取文件名（不含扩展名）
    name = hpp_file.stem

    # 创建.ixx文件路径
    ixx_file = hpp_file.with_suffix('.ixx')

    # 构建.ixx文件内容
    ixx_content = \
f"""export module cango.nstd.type_trans.{name};

export namespace cango {{
{namespace_content}
}};"""

    try:
        ixx_file.write_text(ixx_content, encoding='utf-8')
        print(f"已创建: {ixx_file}")
    except Exception as e:
        print(f"错误: 创建文件 {ixx_file} 失败: {e}")

def process_hpp_file(hpp_file: Path) -> None:
    print(f"处理文件: {hpp_file}")

    # 提取namespace内容
    namespace_content = extract_namespace_content(hpp_file)

    if namespace_content:
        # 创建.ixx文件
        create_ixx_file(hpp_file, namespace_content)
    else:
        print(f"跳过文件: {hpp_file} (未找到namespace内容)")

def process_all_hpp_files(directory: str) -> None:
    # 扫描.hpp文件
    hpp_files = scan_hpp_files(directory)

    if not hpp_files:
        print("未找到.hpp文件，程序退出")
        return


    # 处理每个.hpp文件
    for hpp_file in hpp_files:
        process_hpp_file(hpp_file)

    print(f"处理完成！总共处理了 {len(hpp_files)} 个文件")

def main():
    """
    主函数
    """
    if len(sys.argv) < 2:
        print("用法: python script.py <目录路径>")
        print("示例: python script.py ./src")
        sys.exit(1)

    directory = sys.argv[1]

    process_all_hpp_files(directory)

if __name__ == "__main__":
    main()
