// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-12-08 01:28:37
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
        static void Main()
        {
            using (var output = new StreamWriter(@"E:\xsd_info.log"))
            {
                var set = new XmlSchemaSet();
                ValidationEventHandler handler = (sender, e) => output.WriteLine("Validation {0}: {1}", e.Severity, e.Message);
                set.ValidationEventHandler += handler;

                foreach (var file in Directory.GetFiles(@"E:\DUO\adapters\current\External Components\Berichten", "*.dll", SearchOption.AllDirectories))
                {
                    var asm = Assembly.ReflectionOnlyLoadFrom(file);
                    //  output.WriteLine(asm.FullName);

                    foreach (var resourceName in
                        from resourceName in asm.GetManifestResourceNames()
                        let res = asm.GetManifestResourceInfo(resourceName)
                        where res != null
                        select resourceName)
                    {
                        using (var xsd = asm.GetManifestResourceStream(resourceName))
                        {
                            output.WriteLine(resourceName);
                            if (xsd == null) continue;
                            using (var tr = new XmlTextReader(xsd))
                            {
                                var schema = XmlSchema.Read(tr, handler);
                                // output.WriteLine(schema.TargetNamespace);
                                set.Add(schema);
                            }
                        }
                    }
                }

                set.Compile();
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
prog.cs(1,21): error CS0116: A namespace can only contain types and namespace declarations
Compilation failed: 1 error(s), 0 warnings

#endif
