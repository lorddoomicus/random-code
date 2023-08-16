
Here are some BASH script utilities I've written over the years.

Some of them will require extra software be installed to work.

## Some things here 

You'll find these and more in this folder.

### Arduino scripts
These can be run on the command line, but are meant to be built into droppable apps using Platypus.
These will also require the arduino-cli tools be installed.

arduino-uno-r3.sh - this will compile and upload a sketch to an Arduino R3. It should also work on a Redboard.

arduino-uno-r4-minima.sh - this will compile and upload a sketch to an Arduino R4 Minima.

### Random password scripts
3-random-words.sh - This one will pull the random words from the system dictionary for use with security questions on web sites.

rng_pass.sh - this will generate random passwords of differing complexity using a hardware number generator if available, otherwise using /dev/urandom.

### Social Media Archive Scripts
Every 90 days, I make a full back up of my Google and Facebook data.  These files are archived to s3. These scripts are meant to be droppables built by Platypus.
These will require to have the aws cli tools installed.

archive-facebook.sh - archives the facebook backup file to a given s3 Bucket.

archive-google.sh - archives the google takeout file to a given s3 bucket.

### Some Video Scripts
These scripts will handle properly copying, time-stamping and converting to mp4's for import into shotwell or similar program, the files created by
security camera and dashcams.
These will require to have several media tools installed such as ffmpeg and exiftool installed

It's a fairly complex solution with many parts:

dash_conv.sh - this calls sdvf to copy and time-stamp videos from the dascam's memory card.

sdvf.sh - this does the actual processing of the files.

sec_conv.sh - this calls ssvf to copy and time-stamp videos from the security cam's memory card.

ssvf.sh - this does the acutal processing of the files.

cam_to_mp4.sh - this verifies that we are in the directoris used by the above and calls convmp4.

convmp4.sh - this does the actuall convert to mp4, and sets the meta-data to the proper time-stamp.

extract.sh - This will extract a section of a video, saving the output as an mp4 file.

