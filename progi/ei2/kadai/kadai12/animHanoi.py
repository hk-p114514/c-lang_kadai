#!/bin/python3

from tkinter import *
from tkinter.ttk import *
from tkinter.font import *
import sys
import time

class Disc:
  def __init__(self, canvas, cx, cy, width, height):
    self.canvas = canvas
    self.cx = cx  # 円盤底面中心のx座標
    self.cy = cy  # 円盤底面中心のy座標
    self.width = width
    self.height = height
    x = cx - width / 2
    y = cy - height
    self.discID = canvas.create_rectangle(x, y, x + width, cy, fill="green", outline="black", width=1)

  def moveX(self, x):
    if self.cx < x:
      direction = 1  # 右方向へ移動
    elif self.cx > x:
      direction = -1 # 左方向へ移動
    else:
      return
    accel = 1    # 加速度
    wait = 0.1   # 描画の更新待ち時間
    while self.cx != x:
      if reset:
        break
      if stopping:
        root.update()
        continue
      dx = direction * accel  # dxは移動量
      dist = abs(x - self.cx) # distは移動先までの距離
      if dist < accel:
        dx = dist * direction
        self.cx = x
      else:
        dx = accel * direction
        self.cx = self.cx + dx
      self.canvas.move(self.discID, dx, 0)
      time.sleep(wait)
      self.canvas.update()
      accel = accel * 2 
    return

  def moveY(self, y):
    if self.cy < y:
      direction = 1  # 下方向へ移動
    elif self.cy > y:
      direction = -1 # 上方向へ移動
    else:
      return
    accel = 1    # 加速度
    wait = 0.1   # 描画の更新待ち時間
    while self.cy != y:
      if reset:
        break
      if stopping:
        root.update()
        continue
      dy = direction * accel  # dxは移動量
      dist = abs(y - self.cy) # distは移動先までの距離
      if dist < accel:
        dy = dist * direction
        self.cy = y
      else:
        dy = accel * direction
        self.cy = self.cy + dy
      self.canvas.move(self.discID, 0, dy)
      time.sleep(wait)
      self.canvas.update()
      accel = accel * 2 
    return
  
  def moveDisk(self, src, dst):
    self.moveY(src.cy - src.height - 50)
    self.moveX(dst.cx)
    self.moveY(dst.top)
  
  def free(self):
    self.canvas.delete(self.discID)
   
class Pole:
  def __init__(self, canvas, cx, cy, width, height):
    self.discs = []
    self.canvas = canvas
    self.cx = cx          # 棒の底端の中心のx座標
    self.cy = cy          # 棒の底端の中心のy座標
    self.top = cy         # 棒に刺さっている最上部の円盤上面の中心のy座標
    self.width = width    # 棒の太さ
    self.height = height  # 棒の高さ
    x = cx - width / 2
    y = cy - height
    self.poleID = canvas.create_rectangle(x, y, x + width, cy, fill="brown", outline="black", width=1)
    return

  def push(self, disc):
    self.discs.append(disc)
    self.top = self.top - disc.height
    return

  def pop(self):
    if len(self.discs) == 0:
      return None
    else:
      disc = self.discs.pop()
      self.top = self.top + disc.height
      return(disc)

  def reset(self):
    while len(self.discs) > 0:
      disc = self.pop()
      disc.free()
    return

def hanoi(n, src, dst, work):
  if reset or done:
    pole1.reset()
    pole2.reset()
    pole3.reset()
    return
  if n > 0:
    hanoi(n - 1, src, work, dst)
    disc = src.pop()
    if disc is not None:
      disc.moveDisk(src, dst)
      dst.push(disc)
      hanoi(n - 1, work, dst, src)
    return

def startHanoi():
  global running, stopping, reset
  if stopping:
    stopping = False
    return
  if reset:
    reset = False
  if not running:
    running = True
    hanoi(len(pole1.discs), pole1, pole3, pole2)
    running = False
    if reset:
      reset = False
      running = False
      discSet()
    if done:
      root.destroy()
  return

def stopHanoi():
  global stopping
  stopping = True
  return

def resetHanoi():
  global stopping, reset
  reset = True
  if not running:
    discSet()
  return

def quitHanoi():
  global done
  resetHanoi()
  done = True
  if not running:
    root.destroy()
  return

def discSet():
  if running:
    return
  pole1.reset()
  pole2.reset()
  pole3.reset()
  if spinbox.get() == "":
    n = 1
  else:
    n = (int)(spinbox.get())
  if n > max_discs:
    n = max_discs
    sptxt.set(n)
    spinbox.configure(textvariable=sptxt)
  disc_width = max_disc_width
  i = 0
  while i < n:
    pole1.push(Disc(canvas, pole1.cx, pole1.top, disc_width, disc_thick))
    disc_width = disc_width - max_disc_width / n
    i += 1
  return

root = Tk()
root.title('ハノイの塔')
root.resizable(False, False)
cwidth = 1000
cheight = 600
sx = str(int(root.winfo_screenwidth() / 2 - cwidth / 2))
sy = str(int(root.winfo_screenheight() / 2- cheight / 2))
root.geometry(str(cwidth) + "x" + str(cheight) + "+" + sx + "+" + sy)

# キャンバスの生成
canvas = Canvas(root, width=cwidth, height=cheight, bg="white")
canvas.place(x=0, y=0)
canvas.update()

# ポールの生成と円盤の最大サイズと最大枚数を定義
cx = cwidth / 2
cy = cheight / 2
pole_thick = 20
max_disc_width = 200 + pole_thick
disc_thick = 20
pole_height = 200 + disc_thick
max_discs = (int)(pole_height / disc_thick) - 1
horizon = 370
pole1 = Pole(canvas, cx - 300, horizon, pole_thick, pole_height)
pole2 = Pole(canvas, cx      , horizon, pole_thick, pole_height)
pole3 = Pole(canvas, cx + 300, horizon, pole_thick, pole_height)
canvas.create_line(cx - 300 - max_disc_width / 2, horizon, cx + 300 + max_disc_width / 2, horizon, width=2)

# ウィジェットのスタイル設定
s = Style()
#s.theme_use('classic')
font = tkinter.font.Font(family='sansselif', size=12)
s.configure('MyWidget.TFrame', font=font, background='white', foreground='black')
#s.configure('MyWidget.TButton', font=font, background='white', foreground='black')
s.configure('MyWidget.TButton', font=font, foreground='black')
s.configure('MyWidget.TLabel', font=font, background='white', foreground='black')
s.configure('MyWidget.TSpinbox', anchor=W, font=font, background='white', foreground='black')
#frame = Frame(root, width=200, height=40, padding=16, relief='sunken', bg='white')
frame = Frame(root, style='MyWidget.TFrame')
frame.grid()

# ポール名 A, B, C の表示
pole_label_size = 20
label_A = Label(canvas, text='A', style='MyWidget.TLabel', font=Font(size=pole_label_size))
label_B = Label(canvas, text='B', style='MyWidget.TLabel', font=Font(size=pole_label_size))
label_C = Label(canvas, text='C', style='MyWidget.TLabel', font=Font(size=pole_label_size))
label_A.place(x = cx - 300 - pole_label_size / 2,  y = horizon + 10)
label_B.place(x = cx       - pole_label_size / 2,  y = horizon + 10)
label_C.place(x = cx + 300 - pole_label_size / 2,  y = horizon + 10)

# 操作ボタンをフレーム内に生成
start_btn = Button(frame, text='開始', width='8', style='MyWidget.TButton', command = startHanoi)
quit_btn = Button(frame, text='終了', width='8', style='MyWidget.TButton', command = quitHanoi)
stop_btn = Button(frame, text='中断', width='8', style='MyWidget.TButton', command = stopHanoi)
reset_btn = Button(frame, text='リセット', width='8', style='MyWidget.TButton', command = resetHanoi)
label = Label(frame, text='枚数', style='MyWidget.TLabel')
sptxt = StringVar()
sptxt.set(0)
spinbox = Spinbox(frame, textvariable=sptxt, from_=0, to=max_discs, width='3', font=font, format='%2.0f', command = discSet)
discset_btn = Button(frame, text='セット', width='8', style='MyWidget.TButton', command = discSet)

# 操作ボタンをフレームのグリッドに左から配置
label.grid(row=0, column=0, padx=5, sticky=(N,S,E,W))
spinbox.grid(row=0, column=1, padx=5, sticky=(N,S,E,W))
discset_btn.grid(row=0, column=2, padx=5)
start_btn.grid(row=0, column=3, padx=5)
stop_btn.grid(row=0, column=4, padx=5)
reset_btn.grid(row=0, column=5, padx=5)
quit_btn.grid(row=0, column=6, padx=5)

# 操作ボタンを配置したフレームをキャンバス上に配置
frame.update()
frame.place(x = cx - frame.winfo_width() / 2 - 5, y=horizon + 120)

def appDone():
  quitHanoi()
  return

running = False
stopping = False
reset = False
done = False

root.protocol("WM_DELETE_WINDOW", appDone)

root.mainloop()
