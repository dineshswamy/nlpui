function call_google_speech_engine()
{
	var recognition=new webkitSpeechRecognition();
	recognition.continuous=true;
	recognition.interimResults=true;
	recognition.onstart=function(){
			console.log("Recognition started");
	};
	recognition.onresult=function(event)
	{
		for (var i =event.resultIndex; i<event.results.length; i++) {
			if(event.results[i].isFinal)
			{
				document.getElementById("speech_api_text").innerHTML+=event.results[i][0].transcript;
			}
		};
	};
	recognition.onerror=function(e)
	{
		console.log("Error");
	};

	recognition.onend=function()
	{
			console.log("Speech recognition ended");
	}

	recognition.lang='en-IN';
	recognition.start();
}

