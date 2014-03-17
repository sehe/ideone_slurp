// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2012-10-11 14:34:35
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
public class MessageNameAttribute : Attribute
{
	private readonly string _Name;
	public string Name { get { return _Name; } }
	public MessageNameAttribute(string name)
	{
		_Name = name;
	}

	// Use the hash code of the string objects and xor them together.
	// SEHE: WTF I comment is broken
	public override int GetHashCode()
	{
		return _Name.GetHashCode();
	}

	// Determine if the object is a match to this one.
	public override bool Match(object obj)
	{
		if (obj == this) // SEHE: WTF II Calls Equals in absense of operator==? NRE waiting
			return true;
		if (obj == null) // SEHE: okay...
			return false;
		if (obj is MessageNameAttribute)
		{
			// Combine the hash codes and see if they're unchanged.
			return (((MessageNameAttribute)obj).GetHashCode() & GetHashCode()) == GetHashCode();
			// SEHE: WTF III - wait a minute. So, if our hash code is 0, we'll **always** match?!
			//       If obj.GetHashCode is 0xFFFFFFFF we'll **always** match?
		}
		else
		{
			return false;
		}
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
prog.cs(1,37): error CS0246: The type or namespace name `Attribute' could not be found. Are you missing a using directive or an assembly reference?
Compilation failed: 1 error(s), 0 warnings

#endif
