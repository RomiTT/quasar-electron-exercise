<template>
  <q-dialog ref="dialog" @hide="onDialogHide">
    <q-card class="q-dialog-plugin">
      <div class="version-info">
        <h6>Quasar: {{ $q.version }}</h6>
        <h6>Node.js : <span>{{nodeVersion}}</span></h6>
        <h6>Chrome : <span>{{chromeVersion}}</span></h6>
        <h6>Electron: <span>{{electronVersion}}</span></h6>
      </div>

      <!-- buttons example -->
      <q-card-actions align="right">
        <q-btn color="primary" label="OK" @click="onOKClick" />
        <q-btn color="primary" label="Cancel" @click="onCancelClick" />
      </q-card-actions>
    </q-card>
  </q-dialog>
</template>

<script>
export default {
  props: {
    // ...your custom props
  },
  computed: {
    nodeVersion: {
      get: () => {
        return process.versions.node;
      }
    },
    chromeVersion: {
      get: () => {
        return process.versions.chrome;
      }
    },
    electronVersion: {
      get: () => {
        return process.versions.electron;
      }
    }
  },  

  methods: {
    // following method is REQUIRED
    // (don't change its name --> "show")
    show () {
      this.$refs.dialog.show()
    },

    // following method is REQUIRED
    // (don't change its name --> "hide")
    hide () {
      this.$refs.dialog.hide()
    },

    onDialogHide () {
      // required to be emitted
      // when QDialog emits "hide" event
      this.$emit('hide')
    },

    onOKClick () {
      // on OK, it is REQUIRED to
      // emit "ok" event (with optional payload)
      // before hiding the QDialog
      this.$emit('ok')
      // or with payload: this.$emit('ok', { ... })

      // then hiding dialog
      this.hide()
    },

    onCancelClick () {
      // we just need to hide dialog
      this.hide()
    }
  }
}
</script>

<style scoped>
.version-info {
  text-align: left;
}
.version-info > h6 {
    margin:0;
    padding-left: 2%;
    padding-top: 1%;
    color:blue;
}
</style>
