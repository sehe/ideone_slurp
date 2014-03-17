// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.03
// date:	2013-09-10 09:33:05
// status:	0
// result:	12
// memory:	36688
// signal:	-1
// public:	false
// ------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        var query = new UvwRequestAssignmentManagementBO().GetAll().Where(uvw => (uvw.FK_ProcessStep == 2)
            && (uvw.FK_Entity == 1)
            && (uvw.FK_Manager == 15))
            .Select(p => new ReqSupAdminGridVm
            {
                NameFamily = p.NameFamily,
                RequestDate = p.RequestDate,
                RequestNo = p.RequestNo,
                RequestType = ReqType.GetReqType(p.RequestType),
                RequestEvaluationStatus = ReqEvalStatus.GetReqEvalStatus(p.RequestEvaluationStatus_Aggregation),
            });
    }
}

public class ReqSupAdminGridVm
{
    public string NameFamily;
    public DateTime RequestDate;
    public string RequestNo;
    public string RequestType;
    public string RequestEvaluationStatus;
}

// ReSharper disable InconsistentNaming
public struct UvwRequestAssignmentManagementBO
{
    public IEnumerable<Stuff> GetAll()
    {
        throw new NotImplementedException();
    }
}

public struct Stuff
{
    public int FK_ProcessStep;
    public int FK_Entity;
    public int FK_Manager;
    public string NameFamily;
    public DateTime RequestDate;
    public string RequestNo;
    public int RequestType;
    public int RequestEvaluationStatus_Aggregation;
}

static internal class ReqType
{
    public static string GetReqType(int type)
    {
        switch (type)
        {
            case 1: return "a";
            case 2: return "b";
            case 3: return "c";
            case 4: return "d";
            default: return "";
        }
    }
}

static internal class ReqEvalStatus
{
    public static string GetReqEvalStatus(int agg)
    {
        switch (agg)
        {
            case 1: return "a";
            case 2: return "b";
            case 3: return "c";
            case 4: return "d";
            default: return "";
        }
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

Unhandled Exception: System.NotImplementedException: The requested feature is not implemented.
  at Program.Main (System.String[] args) [0x00000] in <filename unknown>:0 
[ERROR] FATAL UNHANDLED EXCEPTION: System.NotImplementedException: The requested feature is not implemented.
  at Program.Main (System.String[] args) [0x00000] in <filename unknown>:0 

#endif
#if 0 // cmpinfo

#endif
