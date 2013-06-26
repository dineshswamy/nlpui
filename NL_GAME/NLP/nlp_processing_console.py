from __future__ import division
import nltk ,re, pprint
from nltk.stem.wordnet import WordNetLemmatizer
import clips
import time
import os
import os.path as path
import subprocess

from twisted.internet import reactor
from autobahn.websocket import WebSocketServerFactory,WebSocketServerProtocol,listenWS

class SpeechServer(WebSocketServerProtocol):
			def onMessage(self,msg,binary):
				print(msg)

class Agent_rescue:
	def __init__(self,file_location,id,name):
		self.file_location=file_location
		self.id=id
		self.name=name
		self.clips=clips.Environment()

text=''
file_to_write=''
string_to_write=''
file_last_modified=path.getmtime("hypothesis")
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

#agent_green=Agent_rescue('../team/bomber',23,'agentgreen')
#agent_green.clips.Load('../KB/agent_green_kb.clp')
#agent_green.clips.Reset()

def IsFileChanged(file_time,last_mod_time) :
	file_last_modified=path.getmtime("hypothesis")
	if (file_time-file_last_modified)>0 :
		print ("file_last_modified" + file_last_modified +"  "+"current_file_modified" + file_time)
		return True
	else :
		return False

def string_from_pattern(instruction) :
	if re.match("(go\s?to|walk\s?towards|move\s?to|walk\s?front|walk?\sto|run?\sto).*",instruction,re.IGNORECASE):
		place=re.search("(mango\s?tree|coconut\s?tree|neem\s?tree)",instruction,re.IGNORECASE)
		if place:
			return str("walkfront " + str(place.group(0)))
	if re.match("(kill|destroy|fire|shoot|attack|assasinate).*",instruction,re.IGNORECASE):
		place=re.search("((the\s?)?tower\s?guy|man)",instruction,re.IGNORECASE)
		if place:
			return "fire tower guy"
	if re.match("(kill|destroy|fire|shoot|attack|assasinate).*",instruction,re.IGNORECASE):
		place=re.search("(the\s?(man|enemy)\s?in\s?your\s?range|sight)",instruction,re.IGNORECASE)
		if place:
			return "fire tower guy"

	if re.match("(catch|board|enter|get\s?into).*",instruction,re.IGNORECASE):
		place=re.search("((the\s?)?train)",instruction,re.IGNORECASE)
		if place:
			return "catch train"
	if re.match("(blast|blow\s?up|detonate).*",instruction,re.IGNORECASE):
		place=re.search("((the?\s?)?copter)",instruction,re.IGNORECASE)
		if place:
			return "blow copter"

	if re.match("(capture|go\s?to|surround|take\s?charge\s?of).*",instruction,re.IGNORECASE):
		place=re.search("((the\s?)?tower)",instruction,re.IGNORECASE)
		if place:
			return "take charge tower"
	else:
		subprocess.call(["espeak","cannot understand your sentence"])
		return instruction

while text!="exit" :

	#if IsFileChanged(path.getmtime("hypothesis"),file_last_modified) :
		
		#print "File modified"
		text=raw_input("=>")
		#hypo_file=open("hypothesis",'w+')
		#text=hypo_file.readline()
		#hypo_file.write('');
		#hypo_file.close()
		
		if text!="" and text!='\n':
			if re.match("agent\s?green.*",text)    :
					file_to_write=chooseAgentFile('agentgreen')
			elif re.match("agent\s?blue.*",text)  :
					file_to_write=chooseAgentFile('agentblue')
			elif  re.match("agent\s?lgreen.*",text) :
					file_to_write=chooseAgentFile('agentlgreen')
			elif  re.match("agent\s?orange.*",text) :
					file_to_write=chooseAgentFile('agentorange')
		 
		if file_to_write!='':
				print file_to_write
				if text!="":
					file_agent=open(file_to_write,'w')
					string_to_write=re.sub(r'agentorange|agentblue|agentgreen|agentlgreen',"",text)
					string_to_write=string_to_write.strip()
				if text!='' :
					string_to_write=string_from_pattern(string_to_write)
					file_agent.write(string_to_write)
					time.sleep(3)

				print "...preprocessed text"
				
				print string_to_write
				#print "Doing lemmatization"
				#lemmatize_words(string_to_write)
				#print "...applying POS TAG"
				#part_of_speech_tagging(string_to_write)
				file_agent.close()
		else :
			subprocess.call(["espeak","who you are taking to"])
			