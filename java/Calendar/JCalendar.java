/////////////////////////////////////////////////////////////////////////////////////////
package Calendar;

import java.util.*;
public class JCalendar {
 private Calendar cal;
 private int year;    //연
 private int month;    //월
 private int today;    //오늘
 private int firstdayOfWeek;  //1일의 요일
 private int lastday;   //한달의 최대 날짜

 public JCalendar() {

  cal = Calendar.getInstance();
  year = cal.get(Calendar.YEAR);
  month = cal.get(Calendar.MONTH);
  today = cal.get(Calendar.DAY_OF_MONTH);

  setCalendar(year, month, 1);
 }
 public void setCalendar(int year, int month, int date) {

  cal.set(year, month, date);
  this.year = year;
  this.month = month;
  firstdayOfWeek = cal.get(Calendar.DAY_OF_WEEK) - 1;
  lastday = cal.getActualMaximum(Calendar.DAY_OF_MONTH);

 }
 public void setFirstdayOfWeek(int firstdayOfWeek) {
  this.firstdayOfWeek = firstdayOfWeek;
 }
 public Calendar getCal() {
  return cal;
 }
 public int getFirstdayOfWeek() {
  return firstdayOfWeek;
 }
 public int getLastday() {
  return lastday;
 }
 public int getMonth() {
  return month;
 }
 public int getToday() {
  return today;
 }
 public int getYear() {
  return year;
 }

}
