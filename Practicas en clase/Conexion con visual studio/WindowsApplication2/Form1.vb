Public Class Form1
    Dim sp As String
    Dim msg As String


    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Button6.BackColor = Color.Gray
        Button3.Enabled = False
        Timer1.Start()
        For Each sp As String In My.Computer.Ports.SerialPortNames
            ComboBox1.Items.Add(sp)
        Next
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            SerialPort1.PortName = ComboBox1.Text()
            SerialPort1.Open()
            System.Threading.Thread.Sleep(200)
            SerialPort1.Write("D")
            System.Threading.Thread.Sleep(100)
            sp = SerialPort1.ReadExisting()
            If sp = "0" Then
                Button6.BackColor = Color.Black
            End If
            If sp = "1" Then
                Button6.BackColor = Color.Red
            End If
            Button3.Enabled = True
            Button1.Enabled = False
        Catch
            MessageBox.Show("Ha ocurrido un error al abrir el puerto, verifique que el puerto seleccionado sea correcto.")

        End Try

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        SerialPort1.Close()
        Button6.BackColor = Color.Gray
        Button3.Enabled = False
        Button1.Enabled = True
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        If SerialPort1.IsOpen = False Then
            msg = "Debe conectarse Primero"
            MsgBox(msg)
            Exit Sub
        End If
        SerialPort1.Write("B")
        System.Threading.Thread.Sleep(100)
        sp = SerialPort1.ReadExisting()
        If sp = "0" Then
            Button6.BackColor = Color.Black
        End If
        If sp = "1" Then
            Button6.BackColor = Color.Red
        End If
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        If SerialPort1.IsOpen = False Then
            msg = "Debe conectarse Primero"
            MsgBox(msg)
            Exit Sub
        End If
        SerialPort1.Write("A")
        System.Threading.Thread.Sleep(100)
        sp = SerialPort1.ReadExisting()
        If sp = "0" Then
            Button6.BackColor = Color.Black
        End If
        If sp = "1" Then
            Button6.BackColor = Color.Red
        End If
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        If SerialPort1.IsOpen = False Then
            msg = "Debe conectarse Primero"
            MsgBox(msg)
            Exit Sub
        End If
        SerialPort1.Write("C")
        System.Threading.Thread.Sleep(100)
        sp = SerialPort1.ReadExisting()
        If sp = "0" Then
            Button6.BackColor = Color.Black
        End If
        If sp = "1" Then
            Button6.BackColor = Color.Red
        End If
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        If SerialPort1.IsOpen = True Then
            SerialPort1.Write("D")
            System.Threading.Thread.Sleep(100)
            sp = SerialPort1.ReadExisting()
            If sp = "0" Then
                Button6.BackColor = Color.Black
            End If
            If sp = "1" Then
                Button6.BackColor = Color.Red
            End If
        End If
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
  
    End Sub
End Class


