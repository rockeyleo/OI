from aip import AipSpeech

APP_ID = '24753572'
API_KEY = '2Ebel4Lji7x2OWs51ufquyph'
SECRET_KEY = 'nTt45xMXCEBIuqtvdIzAmBGremDs0Vg7'

client = AipSpeech(APP_ID,API_KEY,SECRET_KEY)

def get_file(filePath):
    with open(filePath,'rb') as fp:
        return fp.read()

print(client.asr(get_file('16k.wav'),'pcm',16000,{'dev_pid':1537,}))
