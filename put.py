import requests
import random
c=0
z=input("请输入注册数量:")
url=input("Url:")
for num in range(1,int(z)+1):
  t=str(random.randint(100000,9999999999))
  headers={'content-type':'application/x-www-form-urlencoded'}
  data={'email':t+'@nmsl.com','password':t,'password_confirmation':t,'checkTos':'true'}

  r=requests.put(url,data=data,headers=headers)
  if int(r.status_code)==201 :
   c=c+1
   print("注册第{0}个".format(c))
  else :
   print("注册失败")
