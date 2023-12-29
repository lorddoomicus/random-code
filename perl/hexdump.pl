#!/usr/bin/perl
#
# hexdump.pl - produces a simple hexdump 
#
# Make droppable with:
#
# platypus -D -a "Hexdump" -o 'Text Window' -p /opt/local/bin/perl -I org.doomy.Application -u "Derrik Walker" -V 1.0  hexdump.pl 
#
# This can also be run via the CLI
#
# Derived from a MacPerl script that was written in the 1990s.
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2023-08-30	dwalker		Initial Modernized Version

$fnum = 0; 

if ( $ENV{"__CFBundleIdentifier"} eq "org.doomy.Application" ) { 

	# $fnum = 1; 
	if ( $#ARGV < $fnum ) { die "Drop some files on me!!!\n" }

} else { 
	# $fnum = 0; 
	if ( $#ARGV < $fnum ) { $ARGV[0] = '-'; } # stdin if no files when run on the command line
}

for( $i = $fnum; $i <= $#ARGV; $i++ )
{
	$file = $ARGV[$i];
	$pointer = 0;

	$buffer = "";
	@buffer = ();

	print "Can't open $file: $!\n" unless open FILE, $file;

	if ( $file eq '-' ) { print "File: STDIN\n\n"; } else { print "File: $file\n\n"; }

	while( sysread FILE, $buffer, 16)
	{
		for( $count = 0; $count < 16; $count++ )
		{
			$buffet = substr( $buffer, $count, 1 );
			$buffem = ord( $buffet );
			push @buffer, $buffem;
		}

		printf( "%08lx   ", $pointer );	

		for( $count=0; $count<16; $count++ ) { printf("%02x ", $buffer[$count] ); } # Hex 
	
		print("  ");

 		for( $count = 0; $count < 16; $count++ )
		{ 
			#
			# This will replace tab(x09), newline(x0a), and all non-printable characters from x20 - x7e with a period(.)
			#
			$printable = chr( $buffer[$count] ) =~ /[^x09x0ax20-x7e]/ ? ord(".") : $buffer[$count];

			printf( "%c", $printable ); # ASCII
		}

		printf("\n");

		$pointer+=16;

		$buffer = "";
		@buffer = ();
	}

	close FILE;

	print "\n-----------------------------------------------------------------------------\n\n";
}
