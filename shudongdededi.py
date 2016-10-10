# -*- coding: utf8 -*-
import re
import urllib
url="http://stushudong.sinaapp.com/"
s=urllib.urlopen(url).read()
searchchar = (r'车')                        #搜索
ss=s.replace(" ","")
sss=ss.replace("""
""","")
idchar = 'http://www.openstu.com/comment.php?id='
parentchar = '&parent='
typechar = '&type=comments'
p = re.findall(r"<a.*?href=.*?TreeHole.*?汕大TreeHole\">汕大TreeHole</a>：.*?<br/>.*?回应.*?<",sss,re.I)
for i in p:
    a = re.search('>汕大TreeHole</a>：(.*?)<br/>(.*?)show_comment\((.*?),(.*?),(.*?),(.*?)\)(.*?)id(.*?)回应(.*?)<',i,re.I)
    print a.group(1).decode('utf-8')
    
    if(a.group(9)!=''):
        print '评论',a.group(9).decode('utf-8')
    else:
        print '评论','(0)'
        
    pinglun = idchar
    pinglun += a.group(3)
    pinglun += parentchar
    pinglun += a.group(6)
    pinglun += typechar

    getpinglun = urllib.urlopen(pinglun).read()
    getpinglun = getpinglun.replace(" ","")
    getpinglun = getpinglun.replace("""
""","")
    if(a.group(9)!=''):
        pinglunlist  = re.findall(r"float:left;width:400px;padding-left:5px;padding-bottom:2px;(.*?)</div></li><divclass=",getpinglun,re.I)
        if(pinglunlist==[]):
            print u'获取失败'
        for n in pinglunlist:
            print n.decode('utf-8')
    print '\n' 
else:
    print 'over'



