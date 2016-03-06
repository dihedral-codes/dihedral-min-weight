def cycs(s):
  for i in range(len(s)):
	  print(s[i:] + s[:i])