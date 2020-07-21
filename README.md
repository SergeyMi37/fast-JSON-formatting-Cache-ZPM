 ~~~
 This is a coding example working on Caché 2018.1.3  and IRIS 2020.2 
 It will not be kept in sync with new versions      
 It is also NOT serviced by InterSystems Support !   
~~~ 
# fast JSON formatting (CACHÉ)
It's also an example for a customized command extension (ZZJSN) in Caché & IRIS 
  
This is the Caché version for fast JSON formatting.
It also works in IRIS to make development easier.
To allow parallel existens in IRIS this is named ZZJSN

see:
```
USER>ZWRITE jsn  
jsn="{"Name":"Li,Robert K.","SSN":"672-92-9664","DOB":"1975-01-12","Home":{"Street":"986 Washington Blvd","City":"Boston","State":"PA","Zip":"95802"},"Office":{"Street":"6012 First Place","City":"Reston","State":"MT","Zip":"77739"},"Spouse":{"Name":"Avery,Zelda H.","SSN":"323-13-7437","DOB":"1943-03-27","Home":{"Street":"196 Main Drive","City":"Youngstown","State":"WY","Zip":"53229"},"Office":{"Street":"4056 Franklin Court","City":"Bensonhurst","State":"IA","Zip":"27688"},"FavoriteColors":["Black"],"Age":77},"Age":45,"Title":"Associate Marketing Manager","Salary":10421}" 
```  
This doesn't look so easy to follow.
So this is a shorthand to save time and reduce mistyping.

The attached ZZJSN.inc is to be included into your %ZLANGC00.mac
```  
USER>ZZJSN jsn        ; does the Output to Terminal / Device  
{
  "Name":"Li,Robert K.",
  "SSN":"672-92-9664",
  "DOB":"1975-01-12",
  "Home":{
    "Street":"986 Washington Blvd",
    "City":"Boston",
    "State":"PA",
    "Zip":"95802"
  },
  "Office":{
    "Street":"6012 First Place",
    "City":"Reston",
    "State":"MT",
    "Zip":"77739"
  },
  "Spouse":{
    "Name":"Avery,Zelda H.",
    "SSN":"323-13-7437",
    "DOB":"1943-03-27",
    "Home":{
      "Street":"196 Main Drive",
      "City":"Youngstown",
      "State":"WY",
      "Zip":"53229"
    },
    "Office":{
      "Street":"4056 Franklin Court",
      "City":"Bensonhurst",
      "State":"IA",
      "Zip":"27688"
    },
    "FavoriteColors":[
      "Black"
    ],
    "Age":77
  },
  "Age":45,
  "Title":"Associate Marketing Manager",
  "Salary":10421
}
```  
```  
set st=##class(%Stream.GlobalCharacter).%New()
ZZJSN jsn:st      ; write result to Stream
```  
```  
ZZJSN jsn:"BOBBY"  ; writes it to local variable BOBBY
```  
