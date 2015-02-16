# arduino-projector-mute
Projector Mute
 
 Watches a digital input for state change.
 If gone high to low (external relay on), then send serial command to mute picture.
 If gone low to high (external relay off), then send serial command to un-mute picture.
 Uses interupt to detect state change.
 Runs LED blink in loop to show program is running.
