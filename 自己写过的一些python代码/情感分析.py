# coding=gbk
"""
作者：川川
@时间  : 2021/8/29 21:30
群：970353786
"""
'''
用户想要利用Senta完成对该文件的情感分析预测，只需读入该文件，将文件内容存成list，list中每个元素是待预测句子。
'''
with open("test.txt", 'r') as f:
    try:
        test_text = []
        for line in f:
            test_text.append(line.strip())
    except:
            print('读取失败')
print(test_text)
''':cvar
加载预训练模型,如果想尝试其他模型，只需要更换Module中的name参数即可.
'''
import paddlehub as hub
senta = hub.Module(name="senta_bilstm")
#预测
input_dict = {"text": test_text}
results = senta.sentiment_classify(data=input_dict)

for result in results:
    print(result)