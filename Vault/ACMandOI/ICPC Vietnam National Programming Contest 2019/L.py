var = {}

while True:
	tokens = input().split()
	if tokens[0] == 'end.':
		break
	if tokens[0] == 'var':
		new_variable_name = tokens[1]
		content = ''
		for i in range(3, len(tokens)):
			content += tokens[i]
			if i < len(tokens) - 1:
				content += ' '
		M = len(content)
		content = content[0:M-1]
		if content[0] != '`' and content[0] != '"':
			var[new_variable_name] = var[content]
		else:
			stack = [""]
			initChar = [content[0]]
			id = 0
			for ch in content:
				if ch == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
					stack.append("")
					initChar.append('?')
				elif ch == '{':
					print('', end='')
				elif ch == '}':
					last = stack.pop()
					if initChar.pop() != '?':
						stack[-1] += last
						if len(last) > 0 and last[-1] == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
							tmp = len(stack[-1])
							stack[-1] = stack[-1][0:tmp-1]
							stack.append("")
							initChar.append('?')
					else:
						stack[-1] += var[last]
						if len(var[last]) > 0 and var[last][-1] == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
							tmp = len(stack[-1])
							stack[-1] = stack[-1][0:tmp-1]
							stack.append("")
							initChar.append('?')
				elif ch == '`' or ch == '"':
					initChar[-1] = ch
				else:
					stack[-1] += ch
				id += 1
			var[new_variable_name] = stack[0]
	if tokens[0] == 'print':
		content = ''
		for i in range(1, len(tokens)):
			content += tokens[i]
			if i < len(tokens) - 1:
				content += ' '
		M = len(content)
		content = content[0:M-1]
		if content[0] != '`' and content[0] != '"':
			print(var[content])
		else:
			stack = [""]
			initChar = [content[0]]
			id = 0
			for ch in content:
				if ch == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
					stack.append("")
					initChar.append('?')
				elif ch == '{':
					print('', end='')
				elif ch == '}':
					last = stack.pop()
					if initChar.pop() != '?':
						stack[-1] += last
						if len(last) > 0 and last[-1] == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
							tmp = len(stack[-1])
							stack[-1] = stack[-1][0:tmp-1]
							stack.append("")
							initChar.append('?')
					else:
						stack[-1] += var[last]
						if len(var[last]) > 0 and var[last][-1] == '$' and initChar[-1] == '`' and (id + 1 < len(content) and content[id+1] == '{'):
							tmp = len(stack[-1])
							stack[-1] = stack[-1][0:tmp-1]
							stack.append("")
							initChar.append('?')
					initChar[-1] = ch
				else:
					stack[-1] += ch
				id += 1
			print(stack[0])