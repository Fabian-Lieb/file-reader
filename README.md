# JSON File Reader (C Extension)

## Overview

This project provides a C extension for efficiently reading JSON files within your python applications. It offers a lightweight and performant solution for parsing JSON data, ideal for scenarios where low-level access to JSON content is required.


## Installation

To integrate the JSON file reader extension into your project, follow these steps:

1. **Clone the Repository**: Clone this repository to your local machine using the following command:

2. **Install Dependencies**: C-libarys & python libars

```bash
sudo apt-get install libjansson-dev
```

```bash
pip install -r requirements.txt
```

3. **Compile C-Extension**:gcc -pthread -fPIC -Wno-unused-result -Wsign-compare -DNDEBUG -g -fwrapv -O3 -Wall -shared -o json_extension.so json_extension.c -I/usr/include/python3.10 -lpython3.10 -ljansson

## Usage

Using the JSON file reader extension in your C python is straightforward. Follow these steps to read JSON files.