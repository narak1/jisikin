/////////////////////////////////////////////////////////////////////////////////////////
package Calendar;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.*;

public class JCalUI implements ActionListener, ChangeListener {
 JFrame frame;     //���� ������
 JPanel calendarPanel;   //�޷� ��ü �г�
 JPanel changePanel;    //JSpinner, JComboBox ��� �ִ� �г�
 JPanel datePanel;    //��¥ �κ� �г�

 JCalendar jcalendar;   //JCalendar ��ü
 ArrayList<JLabel> dateList;  //��¥JLabel�� ���� ����Ʈ

 JSpinner changeYear;
 JSpinner changeMonth;

 public JCalUI() {

  frame = new JFrame();
  calendarPanel = new JPanel();
  changePanel = new JPanel();
  datePanel = new JPanel();

  jcalendar = new JCalendar();
  dateList = new ArrayList<JLabel>();

  calendarPanel.setBorder(new TitledBorder(new BevelBorder(BevelBorder.RAISED), "Java Calendar"));
  calendarPanel.setLayout(new BorderLayout());

  SpinnerModel yearModel = new SpinnerNumberModel(jcalendar.getYear(), jcalendar.getYear()-113, jcalendar.getYear()+100, 1);
  changeYear = new JSpinner(yearModel);
  changeYear.setEditor(new JSpinner.NumberEditor(changeYear, "#"));


  SpinnerModel MonthModel = new SpinnerNumberModel(jcalendar.getMonth(), jcalendar.getMonth()-7, jcalendar.getMonth()+4, 1);
  changeMonth = new JSpinner(MonthModel);
  changeMonth.setEditor(new JSpinner.NumberEditor(changeMonth, "#"));

  String[] month = new String[12];
  for (int i = 0; i < month.length; i++) {
   month[i] = i + 1 + "��";
  }




  changeYear.addChangeListener(this);
  changeMonth.addChangeListener(this);

  changeMonth.setPreferredSize(new Dimension(60, 22));
  changePanel.add(changeYear);
  changePanel.add(changeMonth);

  changePanel.setPreferredSize(new Dimension(250, 40));
  calendarPanel.add(BorderLayout.NORTH, changePanel);

  datePanel.setLayout(new GridLayout(7, 7));
  String[] dayOfWeekName = {"��", "��", "ȭ", "��", "��", "��", "��"};
  for (int i = 0; i < dayOfWeekName.length; i++) {
   datePanel.add(addJLabel(dayOfWeekName[i], Color.LIGHT_GRAY));
  }

  if (jcalendar.getFirstdayOfWeek() == 0) {
   jcalendar.setFirstdayOfWeek(7);
  }

  for (int i = 0; i < jcalendar.getFirstdayOfWeek(); i++) {
   JLabel label = addJLabel("", null);
   dateList.add(label);
   datePanel.add(label);
  }

  for (int i = 0; i < jcalendar.getLastday(); i++) {
   JLabel label = addJLabel(i + 1 + "", null);
   dateList.add(label);
   datePanel.add(label);
  }

  int afterEmpty = 42 - jcalendar.getLastday() - jcalendar.getFirstdayOfWeek();
  for (int i = 0; i < afterEmpty; i++) {
   JLabel label = addJLabel("", null);
   dateList.add(label);
   datePanel.add(label);
  }

  setWeekend();

  calendarPanel.add(BorderLayout.CENTER, datePanel);
  Container con = frame.getContentPane();
  con.add(BorderLayout.CENTER, calendarPanel);

  Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
  int x = screenSize.width / 2;
  int y = screenSize.height / 2;

  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  frame.setSize(350, 350);
  frame.setLocation(x - (350 / 2), y - (350 / 2));
  frame.setTitle("Java Calendar Ver 1.0");
  frame.setVisible(true);
  frame.setResizable(false);
  frame.setFocusable(true);
 }

 public JLabel addJLabel(String text, Color color) {
  JLabel label = new JLabel();
  label.setText(text);
  label.setHorizontalAlignment(SwingConstants.CENTER);
  label.setBorder(new EtchedBorder());
  if (color != null) {
   label.setOpaque(true);
   label.setBackground(color);
  }
  return label;
 }

 public void actionPerformed(ActionEvent e) {

  JComboBox obj = (JComboBox)e.getSource();
  int month = obj.getSelectedIndex();
  jcalendar.setCalendar(jcalendar.getYear(), month, 1);
  resetDateList();
 }

 public void stateChanged(ChangeEvent e) {

  JSpinner obj = (JSpinner)e.getSource();
  Integer y = (Integer)obj.getValue();
  int year = y.intValue();
  jcalendar.setCalendar(year, jcalendar.getMonth(), 1);
  resetDateList();
 }

 public void resetDateList() {

  if (jcalendar.getFirstdayOfWeek() == 0) {
   jcalendar.setFirstdayOfWeek(7);
  }

  for (int i = 0; i < jcalendar.getFirstdayOfWeek(); i++) {
   dateList.get(i).setText("");
  }
  for (int i = 0; i < jcalendar.getLastday(); i++) {
   dateList.get(jcalendar.getFirstdayOfWeek() + i).setText(i + 1 + "");
  }
  int afterEmpty = jcalendar.getFirstdayOfWeek() + jcalendar.getLastday();
  int last = dateList.size() - afterEmpty;
  for (int i = 0; i < last; i++) {
   dateList.get(afterEmpty + i).setText("");
  }

  setWeekend();
  datePanel.updateUI();
 }

 public void setWeekend() {

  for (int i = 0; i < dateList.size(); i++) {

   if (i % 7 == 0) {
    dateList.get(i).setForeground(Color.RED);
   }
   else if (i % 7 == 6) {
    dateList.get(i).setForeground(Color.blue);
   }
  }

 }

 public static void main(String[] args) {
  new JCalUI();
 }
}
