// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.05
// date:	2011-08-29 23:57:13
// status:	0
// result:	15
// memory:	38960
// signal:	0
// public:	true
// ------------------------------------------------
using System;
using System.Linq;
using System.Reflection;

using IMyInterface=System.Collections.IEnumerable;

namespace TestThat
{
	class MainClass
	{
		
		public static void Main (string[] args)
		{
			var x = AppDomain.CurrentDomain.GetAssemblies()
			    .SelectMany(a => a.GetTypes())
			    .Where(t => typeof(IMyInterface).IsAssignableFrom(t))
			    .Where(t => !(t.IsAbstract || t.IsInterface))
			    .Except(new [] { typeof(IMyInterface) });

                        // reduce load for ideone.com
                        var r = new Random();
                       	x = x.OrderBy(i => r.Next()).Take(100);
			
			Console.WriteLine(string.Join("\n", x.Select(y=>y.Name).ToArray()));
		}
	}
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
SyncStack
<CreateRangeIterator>c__IteratorD
OrderedSequence`2
<CreateIntersectIterator>c__IteratorA`1
<CreateGroupByIterator>c__Iterator7`4
SynchronizedListWrapper
Grouping`2
BitArray
X509CertificateCollection
MethodCallDictionary
<CreateDistinctIterator>c__Iterator3`1
<CreateTakeWhileIterator>c__Iterator1A`1
ConstructionCallDictionary
String
<CreateExceptIterator>c__Iterator4`1
Collection`1
<CreateCastIterator>c__Iterator0`1
<CreateSkipWhileIterator>c__Iterator18`1
ArrayList
Stack
<CreateSkipIterator>c__Iterator16`1
Lookup`2
HashKeys
RuntimeResourceSet
Dictionary`2
HashValues
KeyContainerPermissionAccessEntryCollection
MethodDictionary
<CreateGroupByIterator>c__Iterator8`3
SystemAcl
<Sort>c__Iterator21
MethodReturnDictionary
ResourceReader
<CreateOfTypeIterator>c__IteratorC`1
<CreateSelectIterator>c__Iterator11`2
ArrayListAdapter
RangedArrayList
AuthorizationRuleCollection
QueryableEnumerable`1
SyncHashtable
DictionaryWrapper
ResourceSet
SynchedSortedList
<CreateJoinIterator>c__IteratorB`4
ListKeys
FixedSizeArrayListWrapper
RawAcl
<CreateWhereIterator>c__Iterator1D`1
ValueCollection
<CreateGroupByIterator>c__Iterator5`2
<CreateRepeatIterator>c__IteratorE`1
List`1
<CreateUnionIterator>c__Iterator1C`1
DictionaryWrapper
<CreateDefaultIfEmptyIterator>c__Iterator2`1
ReadOnlyCollection`1
SyncQueue
AggregateDictionary
<CreateGroupJoinIterator>c__Iterator9`4
<CreateReverseIterator>c__IteratorF`1
ListWrapper
ReadOnlyArrayListWrapper
ApplicationTrustCollection
<CreateSkipWhileIterator>c__Iterator17`1
<CreateSelectManyIterator>c__Iterator14`3
KeyCollection
HashSet`1
<CreateTakeWhileIterator>c__Iterator1B`1
Queue
SynchronizedArrayListWrapper
PermissionSet
ListValues
<ApplyResultSelector>c__Iterator1F`1
IdentityReferenceCollection
SortedList
<CreateSelectManyIterator>c__Iterator13`2
FixedSizeListWrapper
DiscretionaryAcl
<CreateGroupByIterator>c__Iterator6`3
<CreateSelectIterator>c__Iterator10`2
ArrayListWrapper
X509ExtensionCollection
<CreateTakeIterator>c__Iterator19`1
<CreateSelectManyIterator>c__Iterator15`3
Evidence
<CreateWhereIterator>c__Iterator1E`1
<CreateConcatIterator>c__Iterator1`1
Hashtable
ReadOnlyListWrapper
<CreateSelectManyIterator>c__Iterator12`2
NamedPermissionSet

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
