// error:	OK
// langId:	3
// langName:	Perl
// langVersion:	perl 5.16.2
// time:	0
// date:	2012-01-03 17:30:49
// status:	0
// result:	15
// memory:	4728
// signal:	0
// public:	true
// ------------------------------------------------
#!/usr/bin/perl
use strict;
use warnings;

my %funcs=qw(writeln Console.WriteLine readln Console.ReadLine write
Console.Write read Console.Read start Diagnostics.Process.Start exit
Environment.Exit);
$funcs{$_} = "global::System.$funcs{$_}" for keys %funcs;

print <<TOP;
using System;

/* AUTOGENERATED BY HACK COMPILER V 0.1 */
namespace Program
{
    public class MainApp
    {          
        public static void Main(string[] args)
        {   
TOP

while (<>)
{
    s/[\r\n]+$//o; # allow silly windows CrLf
    s/^\s*function\b/public static dynamic /o;
    s/^\s*end\b/}/o;
    s/^\s*#__csc__\b/\/* INLINE C-SHARP CODE *\//o;
    s/^\s*#__end__\b/\/* END *\//o;

    $_ .= '{' if m/^\s*(if|else|while|for)\s*([(]|$)/o;

    if (m/^\s*\bvar\b/o)
    {
        for my $func (keys %funcs) { s/\b$func\b/$funcs{$func}() /g; }
        s/\s*$/;/o;
    }
    for my $func (keys %funcs) { s/^(\s*)\b$func\b(.*)$/$1$funcs{$func}($2);/g; }

    print "\t\t\t$_\n"
}

print <<BOTTOM;

        }
    }
}

BOTTOM

// ------------------------------------------------
#if 0 // stdin
var x = "Hello!"
var y = "World!"

var hello = x+y

writeln hello

var test_num = 5
writeln "test number: {0}", test_num

// THIS IS A COMMENT
/* another damn comment 
   of multiple 
   lines */

while (true)
	write "Enter Name:"
	
	var name = readln
	if (name == "me")
		writeln "THIS IS SO AWESOME!!!"
		writeln "I am me!"
	end
	
	else if(name == "exit")
		writeln "Exiting..."
		exit 0
	end
	
	else
		writeln "NOO!!! :("
		write "I am not 'me'..."
	end
end

#endif
#if 0 // stdout
using System;

/* AUTOGENERATED BY HACK COMPILER V 0.1 */
namespace Program
{
    public class MainApp
    {          
        public static void Main(string[] args)
        {   
			var x = "Hello!";
			var y = "World!";
			
			var hello = x+y;
			
			global::System.Console.WriteLine( hello);
			
			var test_num = 5;
			global::System.Console.WriteLine( "test number: {0}", test_num);
			
			// THIS IS A COMMENT
			/* another damn comment 
			   of multiple 
			   lines */
			
			while (true){
				global::System.Console.Write( "Enter Name:");
				
				var name = global::System.Console.ReadLine();
				if (name == "me"){
					global::System.Console.WriteLine( "THIS IS SO AWESOME!!!");
					global::System.Console.WriteLine( "I am me!");
			}
				
				else if(name == "exit")
					global::System.Console.WriteLine( "Exiting...");
					global::System.Environment.Exit( 0);
			}
				
				else{
					global::System.Console.WriteLine( "NOO!!! :(");
					global::System.Console.Write( "I am not 'me'...");
			}
			}

        }
    }
}


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif