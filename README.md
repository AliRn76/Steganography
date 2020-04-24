

## This Is The Original Image:<br>
![Image of APIs](outside.jpg)
<br><br>
## This Is The Image With The Secret Message<br>
![Image of APIs](secured_outside.jpg)

# In Linux:

<b>For Hide Message:</b>
<br>
<pre>./encode "outside.jpg" "Your message"</pre>
  > your message should be _max 44_ characters
<br>

<b> For See The Message:</b> 
<br>
<pre>./decode "secured_outside.jpg"</pre>
<br>

# In Windows:
### Run cdm (Command Prompt) : 
   * Press windows + R ---> Type 'cmd' or 'cmd.exe'
   * Go To the address of file <br>
                - copy address of the folder<br>
                - paste it on cmd after 'cd' like this ---> ```cd C:\Users\Ali\Desktop\Steganography-master\Steganography-master```
   * Write the following line in cmd
  <br>
  
<b>For Hide Message:</b> 
<br>
<pre>encode.exe "outside.jpg" "Your message"</pre>
 > your message should be _max 44_ characters
<br>
  
<b>For See The Message:</b> 
<br>
<pre>decode.exe "secured_outside.jpg"</pre>
