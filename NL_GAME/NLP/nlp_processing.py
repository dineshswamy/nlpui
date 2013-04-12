from __future__ import division
import nltk ,re, pprint
from nltk.stem.wordnet import WordNetLemmatizer

text=''
file_to_write=''
string_to_write=''
def chooseAgentFile(name):
	return {
				'agentgreen':'../team/bomber',
				'agentblue' :'../team/sniper',
				'agentlgreen':'../team/jumper',
				'agentorange':'../team/firer'
			}[name]
def part_of_speech_tagging(word_to_tag):
	tokens=nltk.word_tokenize(word_to_tag)
	tagged_tokens=nltk.pos_tag(tokens)
	print tagged_tokens
def lemmatize_words(token):
	lmtzr=WordNetLemmatizer()
	l_token=lmtzr.lemmatize(token)
	print l_token


while (text!='exit'):
	text=raw_input(":")
	if "agentgreen" in text :
			file_to_write=chooseAgentFile('agentgreen')
	elif "agentblue" in text :
			file_to_write=chooseAgentFile('agentblue')
	elif  "agentlgreen" in text :
			file_to_write=chooseAgentFile('agentlgreen')
	elif  "agentorange" in text :
			file_to_write=chooseAgentFile('agentorange')
 
	print file_to_write
	file_agent=open(file_to_write,'w')
	string_to_write=re.sub(r'agentorange|agentblue|agentgreen|agentlgreen',"",text)
	string_to_write=string_to_write.strip()
	file_agent.write(string_to_write)

	print "...preprocessed text"
	print string_to_write
	#print "Doing lemmatization"
	#lemmatize_words(string_to_write)
	print "...applying POS TAG"
	part_of_speech_tagging(string_to_write)
	file_agent.close()



