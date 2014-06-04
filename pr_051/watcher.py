#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : watcher.py
# Creation Date : 16-05-2014
# Last Modified : Fri 16 May 2014 11:50:11 AM BST
# Created By : Greg Lyras <greglyras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/
import pyinotify
import os


def newfile(event):
  os.system("make")
  os.system("./main")

wm = pyinotify.WatchManager()
notifier = pyinotify.Notifier(wm, newfile)

wm.add_watch(os.getcwd()+"/main.cpp", pyinotify.IN_MODIFY)

notifier.loop()
