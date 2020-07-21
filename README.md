 ~~~
 This is a coding example working on IRIS 2020.2 
 It will not be kept in sync with new versions      
 It is also NOT serviced by InterSystems Support !   
~~~ 
# fast JSON formatting (IRIS)
It's also an example for a customized command extension (ZZJSON) in IRIS 
  
IRIS has a nice %JSON.Formatter class.
But for debugging it is not really handy.  
see:
```
ZWRITE js1  
js1="{""Name"":""Cunningham,John C."",""SSN"":""294-11-9150"",""DOB"":""1933-01-08"",""Home"":{""Street"":""4249 Ash Street"",""City"":""Tampa"",""State"":""MD"",""Zip"":""30176""},""FavoriteColors"":\[""White"",""Red"",""Green""]}"   
```  
so you proceed  for the most simple case  
```    
set formatter=##class(%JSON.Formatter).%New()   
do formatter.Format(js1)  
{   
  "Name":"Cunningham,John C.",  
  "SSN":"294-11-9150",  
  "DOB":"1933-01-08",  
  "Home":{  
     "Street":"4249 Ash Street",  
     "City":"Tampa",  
     "State":"MD",  
     "Zip":"30176"  
  },  
  "FavoriteColors":\[  
    "White",  
    "Red",  
    "Green"  
  ]  
}  
```  
Not a big thing.   
You do it once, you do it twice, and after the 5th time your fingers get tired.

So this is a shorthand to save time and reduce mistyping.

The attached ZZJSON.inc is to be included into your %ZLANGC00.mac
```  
ZZJSON js1         ; does the Output to Terminal / Device  
```  
```  
set st=##class(%Stream.GlobalCharacter).%New()
ZZJSON js1:st      ; write result to Stream
```  
```  
ZZJSON js1:"BOBBY"  ; writes it to local variable BOBBY
```  
