

def comb(d, rows):
  d = [1 if i == '1' else 0 for i in d]
  rows = [1 if i == '1' else 0 for i in rows]
  
  output = [0] * len(d)

  for i in range(len(rows)):
    if rows[i] == 1:
      cyc = d[i:] + d[:i]
      output = [((cyc[j] + output[j]) % 2) for j in range(len(output))]
  
  return "".join(list(map(str, output)))