// error:	OK
// langId:	29
// langName:	PHP
// langVersion:	php 5.4.4
// time:	0
// date:	2012-09-12 10:15:43
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
DO 
if Request.Form("Action") = "CREATE" and strCreate = "Y" then 
IF strPersonId <> "" then 
for iLoop = 0 to UBound(astrSubTest) 
if Request.Form(astrSubTest(iLoop) & "CodeID") <> "" then 
if DBConnNextKey.Errors.Count > 0 then 
for iLoop2 = 0 to DBConnNextKey.Errors.Count - 1 
next 
exit do 
end if 
if Request.Form(astrSubTest(iLoop) & "V") = "" then 
else 
end if 
if DBConnU.Errors.Count > 0 then 
exit for 
end if 
end if 
next 
if DBConnU.Errors.Count = 0 then 
else 
for iLoop2 = 0 to DBConnU.Errors.Count - 1 
next 
end if 
End IF 
end if 
if Request.Form("Action") = "UPDATE" and strUpdate = "Y" then 
IF strPersonId <> "" then 
for iLoop = 0 to UBound(astrSubTest) 
if Request.Form(astrSubTest(iLoop) & "ID") = "" then 'row does not exist 
if Request.Form(astrSubTest(iLoop) & "CodeID") <> "" then 'Create 
if DBConnNextKey.Errors.Count > 0 then 
for iLoop2 = 0 to DBConnNextKey.Errors.Count - 1 
next 
exit do 
end if 
if Request.Form(astrSubTest(iLoop) & "V") = "" then 
else 
end if 
end if 
elseif Request.Form(astrSubTest(iLoop) & "CodeID") = "" then 'Delete 
else 'Update 
if Request.Form(astrSubTest(iLoop) & "V") = "" then 
else 
end if 
end if 
if strSQL <> "" then 
end if 
if DBConnU.Errors.Count > 0 then 
exit for 
end if 
next 
if DBConnU.Errors.Count = 0 then 
else 
for iLoop = 0 to DBConnU.Errors.Count - 1 
next 
end if 
End IF 
end if 
if Request.Form("Action") = "DELETE" and strDelete = "Y" then 
IF strPersonId <> "" then 
for iLoop = 0 to UBound(astrSubTest) 
if Request.Form(astrSubTest(iLoop) & "ID") <> "" then 'row exists 
end if 
next 

if DBConnU.Errors.Count = 0 then 
else 
for iLoop = 0 to DBConnU.Errors.Count - 1 
next 
end if 
End IF 
end if 
LOOP UNTIL TRUE 
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
