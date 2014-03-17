// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-09-18 13:53:47
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
    public abstract class BaseComponent : MarshalByRefObject, IMessageHandler, IComponentManagement
    {
        private static readonly object _instanceLock = new object();
        private static volatile BaseComponent _instance;
        private static volatile string _name;

        private BaseComponent()
        {
            throw new BaseComponentCreateException(String.Format(PrivateErrors.BaseComponentPrivateConstructorError));
        }

        protected BaseComponent(string name)
        {
            _name = name;

            if (_instance == null)
            {
                lock (_instanceLock)
                {
                    if (_instance == null)
                    {
                        _instance = this;
                    }
                }
            }
            else
            {
                throw new BaseComponentCreateException(String.Format(PrivateErrors.BaseComponentConstructorError));
            }
        }

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cs(31,1): error CS8025: Parsing error
Compilation failed: 1 error(s), 0 warnings

#endif
