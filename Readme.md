# 配置VSCode C++ 环境
1. F5  添加C++(GDB/LLDB) 
生成 launch.json文件，修改

{  
    // Use IntelliSense to learn about possible attributes.  
    // Hover to view descriptions of existing attributes.  
    // For more information, visit: https://go.microsoft.com/  fwlink/?linkid=830387  
    "version": "0.2.0",  
    "configurations": [  
        {  
            "name": "(gdb) Launch",  
            "type": "cppdbg",  
            "request": "launch",  
            "program": "${workspaceFolder}/a.out",  
            "args": [],  
            "stopAtEntry": false,  
            "cwd": "${workspaceFolder}",  
            "environment": [],  
            "externalConsole": true,  
            "MIMode": "gdb",  
            "setupCommands": [  
                {  
                    "description": "Enable pretty-printing for gdb",  
                    "text": "-enable-pretty-printing",  
                    "ignoreFailures": true  
                }  
            ]  
        }  
    ]  
}  


2. shift+ctrl+B 生成tasks.json文件  
{  
    // See https://go.microsoft.com/fwlink/?LinkId=733558  
    // for the documentation about the tasks.json format  
    "version": "2.0.0",  
    "tasks": [  
        {  
            "label": "echo",  
            "type": "shell",  
            "command": "g++ -g -o a.out ${file}",  
            "group": {  
                "kind": "build",  
                "isDefault": true  
            }  
        }  
    ]  
}  


# VSCode 上传 github  
1. 先在github上创建一个新的项目  
2.   
…or create a new repository on the command line  
echo "# ALG_Learning_20200514" >> README.md  
git init  
git add README.md  
git commit -m "first commit"  
git remote add origin https://github.com/skywalkerair/ALG_Learning_20200514.git  
git push -u origin master  