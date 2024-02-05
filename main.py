import time
import json

import json_extension

def c_read():
    """Basic example of how to use the C extension to read a JSON file."""
    start = time.time()
    json_data = json_extension.read_json("config.json")
    end = time.time()
    duration = end - start
    return json_data, duration

def python_read():
    """Basic example of how to use the Python library to read a JSON file."""
    start = time.time()
    with open("config.json", "r") as f:
        json_data = json.load(f)
    end = time.time()
    duration = end - start
    return json_data, duration

def main():
    """Main function to compare the performance of the C extension and the Python library."""
    c_data, c_duration = c_read()
    print(f'C read: {c_duration} seconds')
    python_data, python_duration = python_read()
    print(f'Python read: {python_duration} seconds')

    if c_data == python_data:
        print('Data is the same')
    else:
        print(f"c_data: {c_data}")
        print(f"python_data: {python_data}")

if __name__ == "__main__":
    main()

