#!/usr/bin/perl
#
# bcount.pl - makes a list of count of byte ASCII values in a file sorted by count of each byte
#
# Make Droppable with:
#
# platypus -D -a "Byte Count" -o 'Text Window' -p /opt/local/bin/perl -I org.doomy.Application -u "Derrik Walker" -V 1.0 bytecount.pl
#
# This can also be used via the CLI
# 
# Derived from hexdump.pl and an ancient MacPerl script written in the 1990s. 
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2023-09-01	dwalker		Initial Modernized Version

$fnum = 0; 

if ( $ENV{"__CFBundleIdentifier"} eq "org.doomy.Application" ) { 

	if ( $#ARGV < $fnum ) { die "Drop some files on me!!!\n" }

} else { 
	if ( $#ARGV < $fnum ) { $ARGV[0] = '-'; } # stdin if no files when run on the command line
}

$file = $ARGV[0];

print "Can't open $file: $!\n" unless open FILE, $file;

while (<FILE>) {

	chomp;
	foreach ( split / */ ) { $list{$_} += 1; }
}

printf( "%s\t%s\t%s\n", "Hex","Char","Count" );

foreach my $key ( sort { $list{$a} <=> $list{$b} } keys %list ) {

	my $letter;
	my $ordy = ord( $key ); 
	
	$letter = $key =~ /[^x09x0ax20-x7e]/ ? "-" : $key;  # unprintables ( see hexdump.pl )

	# Print hex_val, char ( if printable ), count
	printf( "%2x\t%s\t%s\n", $ordy, $letter, $list{$key});
}
