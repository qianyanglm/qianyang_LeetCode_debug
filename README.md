# 在Clion上调试LeetCode代码(C++版本)+所有本地题库

 首先这环境不是我做的，是这个人做的，需要环境的人给做环境的star哈
[https://github.com/zzh799/LeetCode_LocalDebug_Cpp?spm=a2c6h.12873639.article-detail.6.8cd36fddXrTNZ5](https://github.com/zzh799/LeetCode_LocalDebug_Cpp?spm=a2c6h.12873639.article-detail.6.8cd36fddXrTNZ5)

上面链接的答主的教程依然可用，按照教程走就行。环境直接clone,插件直直接安装就行。
如果不想用leetcode editor，用LeetCode with labuladong的插件效果也是一样的。

# 本地题库

我会把我所有刷的题目上传，大家可以直接clone下来，然后在本地调试，不用再自己写main函数了，直接调试就行，代码全都是我自己提交成功后才上传的。代码也是放在

## leetcode\editor\cn文件夹

下，但是我也我是初学者，今年九月求职，代码学的都会上传的，代码写的不好，大家可以自己优化，我也会不断优化我的代码。创建此仓库只是感到震惊，leetcode那么多年都没有一个可调试的本地代码上传。(
大概率会用官方代码，我自己创新能力一般，一般只会学会官方代码)

总结:我用[https://github.com/zzh799](https://github.com/zzh799)
他的环境，只是把题目数量增加了。

2023.5.22更新，leetcode插件代码模板改为
增加了一些东西

${question.content}
\#include "include/headers.h"

${question.code}

int main()
{
Solution s;
vector<int> data{7, 1, 5, 3, 6, 4};
vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
auto res = "Hello LeetCode";
cout<<res<<endl;

    return 0;

}