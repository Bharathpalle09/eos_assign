str1=sunbeam
str2=bharath
if [ -z $str3 ]
then 
	echo "the string is empty"
else
	echo "the string is not empty"
fi

str3=$str1$str2
echo "str3=$str3"
echo "$str[3]"


str=madam
rstr=`echo $str|rev`
if [ str = rstr ]
then 
	echo "the string is a polindrom"
else
	echo "the string is not a polindrome"
fi
