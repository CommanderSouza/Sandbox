package com.commandersouza.sandbox

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import org.w3c.dom.Text

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val msgToEncrypt = findViewById<EditText>(R.id.tvMessageToEncrypt)
        val msgEncrypted = findViewById<TextView>(R.id.tvEncryptedMessage)

        val buttonEncrypt = findViewById<Button>(R.id.bEncrypt)
        buttonEncrypt.setOnClickListener {
            val text = msgToEncrypt.text.toString()
            msgEncrypted.text = encryptText(text)
        }

        val bChecksum = findViewById<Button>(R.id.bChecksum)
        bChecksum.setOnClickListener {
            val text = msgToEncrypt.text.toString()
            msgEncrypted.text = checksumText(text).toString()
        }
    }

    companion object {
        init {
            System.loadLibrary("encrypt")
        }
        external fun encryptText(txt: String): String
        external fun checksumText(txt: String): Int
    }
}