## "月亮"(moon.c/cpp)

##### 时间限制  2s

#####空间限制  2048MB

#### 题目背景

![image-20220205232202779](C:\Users\asus\AppData\Roaming\Typora\typora-user-images\image-20220205232202779.png)

（来源：百度百科 ”诡秘之主-月亮“ 词条）

#### 题目大意

红月之夜是灵性最为旺盛的时间，因此也最不适宜熬炼和服食魔药。

然而你连超凡者都不是，当然连这种事情也不知道。

为了调制魔药，你收集了 $n$ 种辅助材料，编号从$1$ 到 $n$，编号为 $i$ 的辅助材料能提供 $a_i$ 点灵性。

由于你可能还想给你家的狗也喂一份魔药，以观察魔药是否炼制成功，因此你需要炼制两份魔药。

为了保证你和你家的狗喝到一样的魔药，所以你需要保证这两份魔药所用到的辅助材料提供的灵性之和相等。

每种辅助材料你只有一份，为了保持完整性，每份辅助材料要么不被两份魔药中的任何一份使用，要么被其中恰好一份完整的使用。

为了方便区分，你将两瓶魔药分别标号为 `1` 和 `2`，这样每份辅助材料要么不被使用，要么被 `1` 使用，要么被 `2` 使用。

现在你想要知道有多少种分配方案（即决定每份辅助材料被哪瓶魔药使用或者都不被使用），使得被 `1` 使用的辅助材料提供的灵性之和等于被 `2` 使用的辅助材料提供的灵性之和？

注意：在神秘学领域中，只有主要材料才是必须添加的，辅助材料可以不添加，因此允许某份魔药不适用任何辅助材料。此时，该份魔药所使用的辅助材料提供的灵性之和是零。

#### 一句话题意

给一些数问有多少种将其分为三个集合的方案使得前两个集合内的数字之和相等。

#### 输入文件(moon.in)

本题每个测试点有多组数据。

第一行一个正整数 $T$ 表示数据组数。

对于其中的每组数据：

第一行一个正整数 $n$；

接下来一行 $n$ 个非负整数 $a_1,...,a_n$。

####输出文件(moon.out)

$T$ 行，第 $i$ 行一个整数表示第 $i$ 组数据的答案。

#### 数据范围

本题共 $25$ 个测试点，其中的第 $1\le i\le 25$ 个测试点满足 $n=i+1$。

对于全部的 $25$ 个测试点满足 $0\le a_i\le 10^9,1\le T\le 5$。

#### 提示

黑夜女神教会贝克兰德分教堂提醒您：

魔药不熬对，喝完就要跪。

多测不清空，爆零两行泪。
