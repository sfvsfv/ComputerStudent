def triangle(a,b,c):
    if a <= 0 or b <= 0 or c <= 0:
        print('三角形的三边必须是大于0的数')
    elif a + b <= c or b + c <= a or c + a <= b:
        print('两边之和大于第三边')
    else:
        print('该三个数可以构造三角形！')
a=float(input('请输入边长 a:'))
b=float(input('请输入边长 b:'))
c=float(input('请输入边长 c:'))
triangle(a,b,c)



