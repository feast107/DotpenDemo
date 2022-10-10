# DotpenDemo [麒麟](https://www.kylinos.cn/)互认证点阵笔Demo

+ 由[纸面签批](https://github.com/feast107/PaperSign)提取出视图和逻辑
+ 点阵笔SDK由[腾千里](https://www.tqltech.com/)提供   

![QT](https://img.shields.io/badge/QT-5.6.1-01cc33)
![Kylin-OS](https://img.shields.io/badge/Kylin--OS-10.0-ff0000)
![语言-C++11](https://img.shields.io/badge/Lang-C++11-00aaff)
![SDK](https://img.shields.io/badge/SDK-1.0.0-ff22ff)
![QtTool](https://img.shields.io/badge/QtTool-1.0.0-00ccaa)

---
<img src="https://www.qt.io/hubfs/qt-design-system/assets/logos/qt-logo.svg"  height=50 alt="QT"/> 
<img src="https://www.kylinos.cn/static/pc/new/images/logo.png" margin="0" height=50  alt="QT"/>
<img src="https://tqloss.oss-cn-beijing.aliyuncs.com/tqltech/config/LOGO%20%E5%AE%98%E7%BD%91.png" height = 50 alt="腾千里" >

---

# 开始
一个精简的基架

## 预览一下
<img src="./.docs/MainView.png" width=700>
<img src="./.docs/SignView.png" width=350>
<img src="./.docs/SignViewDrawed.png" width=350>


---
## 目录结构
|目录|描述|
|:---:|:---|
|[Component](./Component/README.md)|工作的核心组件|
|[Configuration](./Configuration/README.md)|主要配置项，预定义的字符串|
|[Drawer](./Drawer/README.md)|笔迹绘制器|
|[Form](./Form/README.md)|页面目录|
|[Include](./Include/README.md)|SDK头文件目录|
|[lib](./lib/)|静态库目录|
|[Models](./Models/README.md)|模型层|
|[Resource](./Resource/)|静态资源|
|[SDK](./SDK/)|SDK库目录|

---
## 外部导入

### [QtTool](https://github.com/feast107/QTTool)   

构建之后将项目下的 `Include` 目录添加到 `DotpenDemo.pro` 项目文件中   
``` qt
INCLUDEPATH += {...}/QtTool/Include //包含目录
DEPENDPATH += {...}/QtTool/Include //依赖目录
```
生成的静态库文件添加到
``` qt
LIBS += {...}/ -lQtTool //动态
PRE_TARGETDEPS += {...}/ -libQtTool //静态
```
或者自行移动到 `lib` 目录下

`pch.h` 文件中已经包含了对 `QtTool` 的引用
``` c++
#include<QtTool_global.h>
```