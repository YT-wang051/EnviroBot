# EnviroBot 校园环境监测小车

> 基于 HiHope WiFi-IoT Hi3861 开发板的多功能智能环境监测小车
---
## 📌 项目简介
本项目是一款基于HiHope WiFi-IoT Hi3861开发板官方仓库开发的智能环境监测小车，实现了基础移动控制与数据上传功能，可用于校园环境监测等场景，在官方代码的基础上，定制化循迹、避障等功能，同时增加了BME280温湿度传感器和GY-30光照强度传感器相关模块。

## ✨ 功能特性
🌡️ 环境数据采集：通过 BME280 传感器实现温湿度检测
💡 光照强度检测：GY-30 传感器采集环境光照数据
🚗 小车基础控制：实现前进、后退、转向等基础动作
📶 WiFi 通信：支持环境数据实时上传与远程控制
📱 小程序控制：支持微信小程序远程操控小车移动

## 🛠️ 技术栈与依赖
- 硬件平台：HiHope WiFi-IoT Hi3861SPC021 开发板
- 开发语言：c
- 开发环境：DevEco Device Tool
- 传感器：BME280（温湿度）、GY-30（光照）

## 🚀 快速开始
### 1. 环境搭建
1.  安装 DevEco Device Tool，配置 Hi3861 开发板编译环境
2.  安装项目依赖的传感器驱动库

### 2. 下载代码
```bash
git clone https://github.com/YT-wang051/EnviroBot.git
cd EnviroBot
./build.sh

## 📂 项目结构
EnviroBot/
├── app/demo/src/# 源代码
├── drivers/ # 传感器与硬件驱动
└── README.md # 项目说明文件
