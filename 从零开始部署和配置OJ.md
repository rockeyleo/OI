# 从0开始安装和部署OJ系统——以UOJ为例

*写在最前面：当前Ubuntu操作系统的用户名为XC，密码为`281602904`*

## 安装UOJ

0. 给电脑安装Ubuntu系统

   [2020最详细安装Ubuntu指南 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/135953477)

   可参考该文章`安装软件`之前的篇目

1. 重设root用户

   在终端（可用ctrl+alt+t快速进入）中输入：

   ```bash
   sudo -i
   passwd
   *输入两遍密码，两遍之间需要按回车。此时屏幕没有显示，之后再按一下回车*
   成功后显示：已成功更新密码
   ```

   *注：接下来的一切与终端有关的操作均需要在root管理员下进行。如果你在重设root用户之后重新进入了终端，则需要再次输入`sudo -i`并回车输入密码（此时也无回显）。

2. 安装docker

   [Ubuntu Docker 安装 | 菜鸟教程 (runoob.com)](https://www.runoob.com/docker/ubuntu-docker-install.html)

   - 安装docker所需要的环境`curl`

     ```bash
     apt update
     ```

     推荐在安装前进行update命令。

     ```bash
     apt intstall curl
     ```

     *注：在提示”您希望继续进行吗？[Y/n]“时按下回车以继续

   - 安装docker本体

     ```bash
     curl -sSL https://get.daocloud.io/docker | sh
     ```

   - 之后将docker添加到开机启动

     ```bash
     systemctl enable docker
     ```

3. 安装portainer汉化版

   [portainer-ce官网](https://hub.docker.com/r/6053537/portainer-ce)

   ```
   docker run -d --restart=always --name="portainer" -p 9000:9000 -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data 6053537/portainer-ce
   ```

4. 使用浏览器访问`127.0.0.1:9000`并创建一个账户

   *注：第一个注册账号是管理员账号，当前docker系统的用户名是admin，密码是281602904`

5. 安装uoj

   [安装 - UOJ部署指北 (universaloj.github.io)](https://universaloj.github.io/post/安装.html)

   - 点击界面中的开始菜单

   - 点击”local“，之后点击左边的镜像一栏

   - 在”镜像“后的输入框中（前面的docker.io动不了，直接在后面的白色区域内输入）输入：

     `universaloj/uoj-system`

   - 点击”拉取镜像“按钮，之后等待下载，成功时会在右上角提示。

   - 在终端中输入:

     ```bash
     sudo docker run --name uoj -dit -p 80:80 --cap-add SYS_PTRACE universaloj/uoj-system
     ```

     来安装uoj。

     *注：uoj默认部署在80端口上，如果需要修改，需要将`80:80`中的第一个80改为目标端口。如你可以使用
     
     ```bash
     sudo docker run --name uoj -dit -p 81:80 --cap-add SYS_PTRACE universaloj/uoj-system
     ```
     
     来将uoj部署在81端口上。当前xcoj部署在81端口。

6. 配置uoj

   - 使用浏览器进入`127.0.0.1:80`

   - 点击右上角“注册”按钮来注册，第一个账户会作为管理员账户。

     *注：当前uoj的第一个管理员账户的用户名为`admin`，密码为`281602904`

     之后点击右上角的“登录”按钮即可登录。

   - 回到`127.0.0.1:9000`，并点击`uoj`一项右侧的终端图标

   - 点击“链接”按钮，之后出现一个黑色终端

     - 在终端中输入`vim /var/www/uoj/app/.config.php`

       注：此时进入vim编辑模式，使用方向键移动，之后按 `i` 进入插入模式，然后完全用键盘进行编辑。编辑完成后，按`Esc`键返回正常模式，输入`:wq`保存退出。该文件是隐藏文件，如果需要，可能需要通过`ls -a`命令才能看到它。

     - 将`'oj-name' =>`右的单引号内内容改为需要的OJ全名（当前为`济南西城实验中学OnlineJudge`）

     - 将`'oj-name-short' =>`右的单引号内内容改为需要的OJ全名（当前为`XCOJ`）

     - 将`'administrator' =>`右的单引号内内容改为管理员名称（当前为`admin（鹿秀娥老师）`）

     - 将`'admin-email' =>`右的单引号内内容改为需要的管理员联系邮箱（当前为`281602904@qq.com`）

     - 将`'QQ-group' =>`右的单引号内内容改为需要的QQ群（当前为空）

       *注：上面的三项内容会在OJ的“帮助”栏中的“联系方式”栏目中显示。

       其他可选选项参见[系统管理 - UOJ部署指北 (universaloj.github.io)](https://universaloj.github.io/post/系统管理.html)的`全局配置文件`一节。

## 安装moodle学习管理平台

待更新
