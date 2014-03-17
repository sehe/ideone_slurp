// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0.03
// date:	2011-08-24 01:41:11
// status:	0
// result:	15
// memory:	37288
// signal:	0
// public:	true
// ------------------------------------------------
using System.Linq;

class Person
{
	public int Id; 
	public string Name;
}

class Address
{
	public int Id;
	public string Street;
}

class PersonAddress
{
	public int PersonId, AddressId;
}

public class Program
{
	public static void Main(string[] args)
	{
		var personList = new []
		{
			new Person { Id = 1, Name = "Pete" },
			new Person { Id = 2, Name = "Mary" },
			new Person { Id = 3, Name = "Joe" }
		};

		var addressList = new []
		{
			new Address { Id = 100, Street = "Home Lane" },
			new Address { Id = 101, Street = "Church Way" },
			new Address { Id = 102, Street = "Sandy Blvd" }
		};

		var relations = new [] 
		{
			new PersonAddress { PersonId = 1, AddressId = 101 },
			new PersonAddress { PersonId = 3, AddressId = 101 },

			new PersonAddress { PersonId = 2, AddressId = 102 },
			new PersonAddress { PersonId = 2, AddressId = 100 }
		};

		var joined = 
					from par in relations
					join p in personList
						on par.PersonId equals p.Id
					join a in addressList
						on par.AddressId equals a.Id
					select new { Person = p, Address = a };

		foreach (var record in joined)
			System.Console.WriteLine("{0} lives on {1}", record.Person.Name, record.Address.Street);
	}
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Pete lives on Church Way
Joe lives on Church Way
Mary lives on Sandy Blvd
Mary lives on Home Lane

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
