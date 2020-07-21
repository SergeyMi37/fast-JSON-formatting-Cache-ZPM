ROUTINE ZZJSN [Type=INC]
ZZJSN(in,out="")  ; produce pretty JSON output for Caché
    new res,t,zr
    set t=$t,zr=$zr
    set res=$$Do^ZPretty(.in)
    if (out="") {
        write res,! 
        } 
    elseif ($isObject(out) && out.%IsA("%Stream.Object")) {
        do out.Write(res) 
     } 
    else {
        set @out=res
        }
    set $zr=zr if t    
    quit
