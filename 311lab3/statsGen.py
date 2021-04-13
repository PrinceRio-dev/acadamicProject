import time
import threading
import random

#This class generates a random statistic that tends to rise or to fall
       
class statisticsGenerator:
   
   def __init__(self,initvalue, increasing):  #constructor starts thread
      self.value = initvalue
      self.increasing = increasing
      self.loop = True
      
      thread = threading.Thread(target=self.update)
      thread.start()    
       
   def get(self): return self.value
      
   def end(self): self.loop = False
    
   def update(self): 
   
      #Note: random.random() returns a different random number between 0 and 1  
      #      each time it's called.
              
      while self.loop:
         #compute step direction
         if random.random() > 0.5 : dir="up"
         else                     : dir="down"
         
         #impose a bias by occasionally skipping a step
         if random.random() > 0.9:
            if self.increasing       and dir == "down":  continue   #don't take the step down
            elif not self.increasing and dir == "up":    continue   #don't take the step up
                    
         #compute the step size and take the step
         step = random.random()  
         if dir == "up": self.value = self.value+step
         else:           self.value = self.value-step
         
         #take a break
         time.sleep(.2)

           

