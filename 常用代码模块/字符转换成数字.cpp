	string str;
		cin >> str;
		if(str[0] >= '0' && str[0] <= '9'){//字符转换成数字
			int num = 0;
			for(int i = 0; i < str.length(); i++){
				num = num * 10 + (str[i] - '0');
			}