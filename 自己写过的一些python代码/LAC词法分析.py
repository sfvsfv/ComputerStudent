# coding=gbk
"""
作者：川川
@时间  : 2021/8/29 22:10
群：970353786
"""
#读取数据
with open("ci.txt", 'r') as f:
    test_text = []
    for line in f:
        test_text.append(line.strip())
print(test_text)
#加载模块
import paddlehub as hub
module = hub.Module(name="lac")
## 预测
results = module.lexical_analysis(texts=test_text)

for result in results:
    print(result)