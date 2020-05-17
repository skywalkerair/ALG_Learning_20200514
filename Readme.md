# 配置VSCode C++ 环境
1. F5  添加C++(GDB/LLDB) 
生成 launch.json文件，修改

{\<br>
    // Use IntelliSense to learn about possible attributes.\<br>
    // Hover to view descriptions of existing attributes.\<br>
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387\<br>
    "version": "0.2.0",\<br>
    "configurations": [\<br>
        {\<br>
            "name": "(gdb) Launch",\<br>
            "type": "cppdbg",\<br>
            "request": "launch",\<br>
            "program": "${workspaceFolder}/a.out",\<br>
            "args": [],\<br>
            "stopAtEntry": false,\<br>
            "cwd": "${workspaceFolder}",\<br>
            "environment": [],\<br>
            "externalConsole": true,\<br>
            "MIMode": "gdb",\<br>
            "setupCommands": [\<br>
                {\<br>
                    "description": "Enable pretty-printing for gdb",\<br>
                    "text": "-enable-pretty-printing",\<br>
                    "ignoreFailures": true\<br>
                }\<br>
            ]\<br>
        }\<br>
    ]\<br>
}\<br>


2. shift+ctrl+B 生成tasks.json文件

{\<br>
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format\<br>
    "version": "2.0.0",\<br>
    "tasks": [\<br>
        {\<br>
            "label": "echo",\<br>
            "type": "shell",\<br>
            "command": "g++ -g -o a.out ${file}",\<br>
            "group": {\<br>
                "kind": "build",\<br>
                "isDefault": true\<br>
            }\<br>
        }\<br>
    ]\<br>
}\<br>


# VSCode 上传 github
1. 先在github上创建一个新的项目\<br>
2. \<br>
…or create a new repository on the command line\<br>
echo "# ALG_Learning_20200514" >> README.md\<br>
git init\<br>
git add README.md\<br>
git commit -m "first commit"\<br>
git remote add origin https://github.com/skywalkerair/ALG_Learning_20200514.git\<br>
git push -u origin master\<br>