import urllib.request, urllib.error
import json
import time

# python3 virtual_contest.py < register.txt > result.txt

# https://codeforces.com/apiHelp

def api_failed():
	print('Failed')
	exit()

N = int(input())
# 参加メンバー
member = [input() for _ in range(N)]
# 提出ステータス
Submissions = [json.load(urllib.request.urlopen(url='https://codeforces.com/api/user.status?handle=' + s)) for s in member]

for st in Submissions:
	if st['status'] != 'OK':
		api_failed()

# コンテスト一覧
Contest_List = json.load(urllib.request.urlopen(url='http://codeforces.com/api/contest.list'))

if Contest_List['status'] != 'OK':
	api_failed()

# CodeForces Round # のあとの数字
Contest_Number = [-1] * 2000
# CR XYZ の併設個数
Division_Count = [0] * 1000


for contest in Contest_List['result']:
	cname = contest['name']
	valid = ('Codeforces' in cname) and ('Round #' in cname) and ('Div. 3' not in cname) and ('Div. 4' not in cname) and ('Beta' not in cname) and ('Div' in cname) and contest['phase'] == 'FINISHED'

	# Codeforces Round ではない
	if not valid:
		continue

	i = cname.find('#') + 1
	# Round 番号
	m = ''

	while i < len(cname) and cname[i].isdigit():
		m = m + cname[i]
		i += 1

	if len(m) == 0:
		continue
	round_number = int(m)

	Contest_Number[contest['id']] = round_number
	Division_Count[round_number] +=  1


## 参加者の提出状況を取って、総合AC数が0の回を列挙する
# CR XYZ の提出回数
Submission_Count = [0] * 1000

for Submission_Status in Submissions:
	for submit in Submission_Status['result']:

		if submit['contestId'] > 2000 or Contest_Number[submit['contestId']] == -1:
			continue

		round_number = Contest_Number[submit['contestId']]

		if submit['verdict'] == 'OK':
			Submission_Count[round_number] += 1


# 出力する
for contest in Contest_List['result']:
	if Contest_Number[contest['id']] != -1 and Division_Count[Contest_Number[contest['id']]] >= 2 and Submission_Count[Contest_Number[contest['id']]] == 0:
		print(contest['name'])
		print('https://codeforces.com/contest/' + str(contest['id']) + '/my' + '\n')
