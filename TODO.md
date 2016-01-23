# 第一阶段
   在Windows+Cygwin 和 Ubuntu（Linux)上 跑通一个简单的socket程序

## 注意
   - 认真搜索，阅读安装和运行相关命令时，给出的各种提示。
   - 下面所有描述中提到的打开某个文件，都是指用notepad++，atom之类的文本编辑器打开那个文件
   - 当遇到问题，或者有不明白的地方时，做好笔记，先用搜索引擎搜索，之后我们讨论。
   - 搜索引擎尽量用bing.com,而非百度。
   - 不明白一个命令是干什么用的时候，使用bing搜索 ”man 命令名"
   - 不明白代码中的函数、头文件是干什么的时候，使用bing搜索 “c++ 函数/头文件名”
   - 其他不明白的，也用类似的方式搜索。

## Cygwin 相关
Cygwin是在Windows系统上，模拟Linux系统操作界面的一套工具软件

### TODO
* fork github代码到你的github账号下
  * 关于什么是fork，以及在github上如何fork，参考[这篇文章](https://help.github.com/articles/fork-a-repo/) "Keep your fork syncked"之前的内容
* 打开cygwin terminal
* 在cygwin中git clone到本地
  * 关于cygwin与git，参考[这篇博客文章](http://www.cnblogs.com/EasonWu/archive/2012/11/27/git-windows-setup-by-cygwin.html) ”Git访问SSH服务”之前的内容
  * 关于git clone，参考[这篇文章](https://help.github.com/articles/cloning-a-repository/)的“Cloning a repository”部分
* 在JerryQQ文件夹下运行 “make all”命令
  * 别忘了cd命令.
  * 打开Makefile文件，或许你大概能猜到 make all在做什么。试着继续搜搜，看看你的猜想对不对。
* 运行 ”make run"命令，根据提示，启动server.exe,以及client.exe，并观察输出

* 读client.c代码，将下面的问题以注释的方式写在代码中
  * 每个函数调用都做了什么操作，有什么意义？
  * 每个被包含的头文件都在做什么？
  * 修改代码，并重新编译运行试试
* 读server.c代码，将下面的问题以注释的方式写在代码中
   * 每个函数调用都做了什么，有什么意义？
   * 每个被包含的头文件都在做什么？
   * 修改代码，并重新编译运行试试


## Linux 系统相关
Virtualbox是一个虚拟机，可以虚拟一个完整的电脑，包括虚拟的CPU、内存、硬盘、网口等。
Virtualbox下安装的Ubuntu是一个真正意义上的Linux操作系统。

### TODO
* 下载VirtualBox
* 安装Ubuntu操作系统 （英文版的，不要装中文版的)
* 学习如何使用virtualbox和ubuntu，会打开gnome-terminal，运行“ls”命令.
