/*
 * backup.rexx - makes lha backups of filesystems
 *
 * It is required that lha be installed and working.
 * Also requires a config file in rexx:backup.config. 
 * That  is just a list of sources and destination folders
 *
 * For example:
 *	work:	flashcard:backups/full
 * 
 * run with ( assuming its in the rexx: folder ):
 *	rx backup
 *
 * (c) 2024 Derrik Walker v2.0
 * This is licensed for use under the GNU General Pulbic License v2
 *
 * 2024-05-26	dwalker		Initial Version
 */

cmd = "lha -aerx a"		/* lha command */
theDate = date(SORTED)		/* the current date */
conf = "rexx:backup.conf"	/* config file */
count = 0 			/* We do not want to overwrite backups */

if ~ open( 'in', conf, 'r' ) then exit 205 

call open out, "ram:backup", write

do while ~ eof( 'in' )
        line = readln( 'in' )

        if line = "" then leave

	parse var line src ' ' dst

	if ~ exists( src ) then do
		echo src not found
		exit 205
	end

	if ~ exists( dst ) then do
		echo dst not found
		exit 205
	end

	src1 = translate( src, '-', ':' )
	lhafile = dst||src1||thedate".lha"
	

	if exists( lhafile ) then  say lhafile "already exists. Skipping"
	else do
		say "Will backup" src "to" lhafile
		call writeln out, cmd lhafile src
		count = count + 1
	end
end

call close out

/* run the actual commands if we can */
if count > 0 
then
	do
		address command
		conwindow = "CON:0/0/640/100/Backups/Close"

		'newshell' conwindow "ram:backup"
	end
else
	say "Nothing to back up now."

exit
