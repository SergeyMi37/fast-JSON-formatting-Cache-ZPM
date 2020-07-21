ROUTINE ZZJSON [Type=INC]
ZZJSON(in,out="")  ; produce pretty JSON output for IRIS
    new res,t,zr
    set t=$t,zr=$zr
    if (out="") {
        do ##class(%JSON.Formatter).%New().Format(in)
        } 
    elseif ($isObject(out) && out.%IsA("%Stream.Object")) {
        do ##class(%JSON.Formatter).%New().FormatToStream(in,out)
     } 
    else {
        do ##class(%JSON.Formatter).%New().FormatToString(in,.res) 
        set @out=res
        }
    set $zr=zr if t    
    quit
