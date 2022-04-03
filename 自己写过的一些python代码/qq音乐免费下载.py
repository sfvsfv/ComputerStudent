import requests
import json
import os
import prettytable as pt

name = input("请输入你想下载的歌手或歌曲名：")

response = requests.get(f'http://c.y.qq.com/soso/fcgi-bin/client_search_cp?p=1&n=10&w={name}')

data_html = response.text

json_str = data_html[9:-1]

json_dict = json.loads(json_str)
song_list = json_dict['data']['song']['list']
tb = pt.PrettyTable()
tb.field_names = ['序号', '歌名', '歌手', '专辑']
music_info_list = []
count = 0
for song in song_list:
    albumname = song['albumname']  # 专辑
    songname = song['songname']  # 歌名
    singername = song['singer'][0]['name']  # 歌手
    songmid = song['songmid']  # mid
    # print(count, albumname, songname, singername, songmid)
    tb.add_row([count, songname, singername, albumname])
    music_info_list.append([songname, singername, songmid])
    count += 1
print(tb)

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36",
    "cookie": "tvfe_boss_uuid=f509108e9196f8ac; pgv_pvid=209524795; RK=lsANWsnqaJ; ptcz=acaa5397b63d002f724a992ebf0505110f5dd2e351b493ac2371a1dc75d1fab5; Qs_lvt_323937=1623995675; Qs_pv_323937=1937804262829921000; nutty_uuid=f8e9ebcd-53f4-453f-9902-39905dd6b248; eas_sid=w156d2N4j6v3g074V3S6e0B3u5; pac_uid=0_bee740cf393b6; o_cookie=1410613164; fqm_pvqid=05feb130-1b70-45bd-8939-edaca44c58a3; ts_uid=2424799660; LW_uid=H1x6h3q6i3G4z7C8q7I9m370u7; LW_sid=o1c6W3C6l306P1B2d339c8A399; luin=o1410613164; lskey=000100000eb3dc6d08bf5fe4b5478b44f60c822a06c0a334d7c66555fe9ad373ebad18a6227b254fb17a8525; _tucao_custom_info=SDVoV3dIaWtjWFMveXE2K2l4RnN5eTBRaU80TmVUMk5FV083S2Y1N0txL2NYRTlnTWtlM0kxdUlzc3BUZGRpMQ%3D%3D--P%2FYusRev630YfPPu55CPiQ%3D%3D; _tc_unionid=571ccbe6-89fd-4e58-94ae-9e6983c46fb8; pgv_pvi=5039926272; fqm_sessionid=17bb9c0a-43fb-435d-aa60-762d2d171e18; pgv_info=ssid=s6404751490; _qpsvr_localtk=0.21901452991153025; login_type=1; tmeLoginType=2; wxopenid=; psrf_qqaccess_token=8AFA65E85751114371A1DBCD3CD5FC9E; psrf_access_token_expiresAt=1651625473; psrf_qqrefresh_token=195BABCC989D6D84618FF6B930D38474; qm_keyst=Q_H_L_24m9x760e4qHVvj5Xl4LkYv2OfD3RUtqa-n5cPgPFdOWNUjRTiuH-KojCNrk7m4; wxunionid=; qm_keyst=Q_H_L_24m9x760e4qHVvj5Xl4LkYv2OfD3RUtqa-n5cPgPFdOWNUjRTiuH-KojCNrk7m4; psrf_qqunionid=B53BFB03C7631B90BC9ADF8D3FDAAC5B; qqmusic_key=Q_H_L_24m9x760e4qHVvj5Xl4LkYv2OfD3RUtqa-n5cPgPFdOWNUjRTiuH-KojCNrk7m4; wxrefresh_token=; psrf_musickey_createtime=1643849473; uin=1410613164; euin=oKv5oeC5oi6s7n**; psrf_qqopenid=2B0AE4E6BE3D86306F57D02843F0CDB3; ts_last=y.qq.com/n/ryqq/search"
}
while True:
    input_index = eval(input("请输入你要下载的序号(-1退出)："))
    if input_index == -1:
        break
    """下载歌曲"""
    download_info = music_info_list[input_index]
    # print(download_info)
    songMid = download_info[2]
    music_info_url = 'https://u.y.qq.com/cgi-bin/musicu.fcg?data={"req":{"module":"CDN.SrfCdnDispatchServer","method":"GetCdnDispatch", "filename":"M800","param":{"guid":"8846039534","calltype":0,"userip":""}},"req_0":{"module":"vkey.GetVkeyServer","method":"CgiGetVkey","filename":"M800","param":{"guid":"8846039534","songmid":["%s"],"songtype":[0],"uin":"1152921504784213523","loginflag":1,"platform":"20"}},"comm":{"uin":"1152921504784213523","format":"json","ct":24,"cv":0}}' % download_info[2]
    purl = 'https://dl.stream.qqmusic.qq.com/' + requests.get(url=music_info_url, headers=headers).json()['req_0']['data']['midurlinfo'][0]['purl']
    music_data = requests.get(url=purl, headers=headers).content
    if os.path.exists("歌曲下载"):
        os.makedirs("歌曲下载")
    with open(f'歌曲下载/{download_info[0]}-{download_info[1]}.mp3', mode='wb') as f:
        f.write(music_data)
    print(f'{download_info[0]}, 下载完成！！！')