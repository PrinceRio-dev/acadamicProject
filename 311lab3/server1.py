from http.server import BaseHTTPRequestHandler, HTTPServer      #python 3
import mimetypes  #put MimeTypes.py in same folder as the server
import os
from statsGen import statisticsGenerator
from datetime import datetime

hostName = "localhost"
serverPort = 8000

#this is where the server looks for files requested by the browser
root = "."   
os.chdir(root) #change to the html root directory
   
class server(BaseHTTPRequestHandler):

   def do_GET(self):          #this function responds to GET requests

      ti=datetime.now()
      curtime=ti.strftime("\tLast Update was At:\tDate:%D\tTime:%H:%M:%S")
      str_curtime=str(curtime)

      path=self.path
      if path == '/' : path = path + "statsGen.py"
      filename = root+path
      print(filename)
      
      value = stats.get()
      #coverting float value into the string
      str_value = str(value)
      print(value)

      #send the HTTP status message to the browser
      self.send_response(200)
      self.send_header("Access-Control-Allow-Origin", "*")       
      self.end_headers()

      #now send the random number and converting string into bytes
      self.wfile.write(str_value.encode('utf-8'))
      #converting date and time value into bytes 
      self.wfile.write(str_curtime.encode('utf-8'))
                     
  

def notImplemented(self):
    self.send_response(501)    #501 Not Implemented
    self.send_header("Content-type","text/html")
    self.end_headers()
    
       
#only run the server if this module was called from the command line.
#python makes the name different if this module is called by another module.
if __name__ == "__main__":    

    webServer = HTTPServer((hostName, serverPort), server)
    print("Server started http://%s:%s" % (hostName, serverPort))

    startingValue = 2537     #initial value of the statistic

    increasing = True
    stats = statisticsGenerator(startingValue,increasing)
   

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")       
