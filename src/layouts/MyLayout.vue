<template>
  <q-layout view="hHh lpR fFf">
    <!-- About Dialog -->
    <q-dialog v-model="about" persistent>
      <q-card class="bg-primary text-white">
        <q-bar>
          <q-icon name="info"/>
          <div class="text-h6">About</div>
          <q-space />

          <q-btn dense flat icon="close" v-close-popup>
            <q-tooltip content-class="bg-white text-primary">Close</q-tooltip>
          </q-btn>
        </q-bar>

        <q-card-section>
          <div class="text-h6">Quasar Electron Application Information</div> <br>
          Quasar version: {{ $q.version }} <br>
          Node.js version: {{nodeVersion}} <br>
          Chrome version: {{chromeVersion}} <br>
          Electron version: {{electronVersion}}
        </q-card-section>
      </q-card>
    </q-dialog>



    <q-header elevated class="bg-grey-10">
      <!-- Custom Titlebar -->
      <q-bar class="q-electron-drag">
        <img src="~assets/app-icon.png" style="width:1rem; height:1rem;"/>
        <div>Quasar Electron Application</div>

        <q-space />

        <div class="q-gutter-x-md">
          <q-btn dense flat icon="remove" @click="minimize" />
          <q-btn dense flat @click="maximize">
            <q-icon name="crop_square" v-show="isMaximizedWindow() === false"/>
            <q-icon style="font-size: 0.95rem; transform: rotate(180deg)" name="filter_none" v-show="isMaximizedWindow() === true"/>
          </q-btn>
          <q-btn dense flat icon="close" @click="closeApp" />
        </div>
      </q-bar>


      <!-- Menus -->
      <!-- <div class="q-pa-sm q-pl-md row items-center">
        <div class="cursor-pointer non-selectable">
          File
          <q-menu>
            <q-list dense style="min-width: 100px">
              <q-item clickable v-close-popup>
                <q-item-section>Open...</q-item-section>
              </q-item>
              <q-item clickable v-close-popup>
                <q-item-section>New</q-item-section>
              </q-item>

              <q-separator />

              <q-item clickable>
                <q-item-section>Preferences</q-item-section>
                <q-item-section side>
                  <q-icon name="keyboard_arrow_right" />
                </q-item-section>

                <q-menu anchor="top right" self="top left">
                  <q-list>
                    <q-item
                      v-for="n in 3"
                      :key="n"
                      dense
                      clickable
                    >
                      <q-item-section>Submenu Label</q-item-section>
                      <q-item-section side>
                        <q-icon name="keyboard_arrow_right" />
                      </q-item-section>
                      <q-menu auto-close anchor="top right" self="top left">
                        <q-list>
                          <q-item
                            v-for="n in 3"
                            :key="n"
                            dense
                            clickable
                          >
                            <q-item-section>3rd level Label</q-item-section>
                          </q-item>
                        </q-list>
                      </q-menu>
                    </q-item>
                  </q-list>
                </q-menu>
              </q-item>

              <q-separator />

              <q-item clickable v-close-popup @click="closeApp">
                <q-item-section>Quit</q-item-section>
              </q-item>
            </q-list>
          </q-menu>
        </div>

        <div class="q-ml-md cursor-pointer non-selectable">
          Edit
          <q-menu auto-close>
            <q-list dense style="min-width: 100px">
              <q-item clickable>
                <q-item-section>Cut</q-item-section>
              </q-item>
              <q-item clickable>
                <q-item-section>Copy</q-item-section>
              </q-item>
              <q-item clickable>
                <q-item-section>Paste</q-item-section>
              </q-item>
              <q-separator />
              <q-item clickable>
                <q-item-section>Select All</q-item-section>
              </q-item>
            </q-list>
          </q-menu>
        </div>
      </div> -->


      <!-- Main Toolbar -->
      <q-toolbar>
        <q-btn flat dense round @click="leftDrawerOpen = !leftDrawerOpen" aria-label="Menu">
          <q-icon name="menu"/>
        </q-btn>

        <q-toolbar-title>Quasar App</q-toolbar-title>

        <q-btn flat dense round aria-label="Home" to="/">
          <q-icon name="home"/>
        </q-btn>

        <q-btn flat dense round aria-label="About" @click="about = true">
          <q-icon name="info"/>
        </q-btn>
      </q-toolbar>
    </q-header>

    <!-- Left drawer -->
    <q-drawer 
              v-model="leftDrawerOpen" 
              side="left" 
              bordered content-class="bg-grey-2"
              behavior="desktop"
              overlay="true"
    >
      <q-list>
        <q-item-label header>Essential Links</q-item-label>
        <q-item clickable tag="a" target="_blank" href="http://v1.quasar-framework.org">
          <q-item-section avatar>
            <q-icon name="school"/>
          </q-item-section>
          <q-item-section>
            <q-item-label>Docs</q-item-label>
            <q-item-label caption>v1.quasar-framework.org</q-item-label>
          </q-item-section>
        </q-item>
        <q-item clickable tag="a" target="_blank" href="https://github.com/quasarframework/">
          <q-item-section avatar>
            <q-icon name="code"/>
          </q-item-section>
          <q-item-section>
            <q-item-label>Github</q-item-label>
            <q-item-label caption>github.com/quasarframework</q-item-label>
          </q-item-section>
        </q-item>
        <q-item clickable tag="a" target="_blank" href="http://chat.quasar-framework.org">
          <q-item-section avatar>
            <q-icon name="chat"/>
          </q-item-section>
          <q-item-section>
            <q-item-label>Discord Chat Channel</q-item-label>
            <q-item-label caption>chat.quasar-framework.org</q-item-label>
          </q-item-section>
        </q-item>
        <q-item clickable tag="a" target="_blank" href="https://forum.quasar-framework.org">
          <q-item-section avatar>
            <q-icon name="record_voice_over"/>
          </q-item-section>
          <q-item-section>
            <q-item-label>Forum</q-item-label>
            <q-item-label caption>forum.quasar-framework.org</q-item-label>
          </q-item-section>
        </q-item>
        <q-item clickable tag="a" target="_blank" href="https://twitter.com/quasarframework">
          <q-item-section avatar>
            <q-icon name="rss_feed"/>
          </q-item-section>
          <q-item-section>
            <q-item-label>Twitter</q-item-label>
            <q-item-label caption>@quasarframework</q-item-label>
          </q-item-section>
        </q-item>
      </q-list>
    </q-drawer>

    <!-- Main Page -->
    <q-page-container>
      <router-view/>
    </q-page-container>
  </q-layout>
</template>

<script>
import { openURL } from "quasar";
import AboutComponent from "../components/AboutComponent.vue";

export default {
  name: "MyLayout",
  data() {
    return {
      leftDrawerOpen: this.$q.platform.is.desktop,
      about: false
    };
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
    openURL,
    isMaximizedWindow() {
      if (process.env.MODE === 'electron') {
        return this.$q.electron.remote.BrowserWindow.getFocusedWindow().isMaximized()
      }
      return false;
    },
    minimize () {
      if (process.env.MODE === 'electron') {
        this.$q.electron.remote.BrowserWindow.getFocusedWindow().minimize()
      }
    },

    maximize () {
      if (process.env.MODE === 'electron') {
        const win = this.$q.electron.remote.BrowserWindow.getFocusedWindow()

        if (win.isMaximized()) {
          win.unmaximize()
        } else {
          win.maximize()
        }
      }
    },

    closeApp () {
      if (process.env.MODE === 'electron') {
        this.$q.electron.remote.BrowserWindow.getFocusedWindow().close()
      }
    },

    alert() {
      // this.$q.dialog({
      //   title: 'Alert',
      //   message: 'Some message'
      // }).onOk(() => {
      //   console.log('OK')
      // }).onCancel(() => {
      //   console.log('Cancel')
      // }).onDismiss(() => {
      //   console.log('I am triggered on both OK and Cancel')
      // })

      this.$q
        .dialog({
          component: AboutComponent,

          // optional if you want to have access to
          // Router, Vuex store, and so on, in your
          // custom component:
          root: this.$root,

          // props forwarded to component
          // (everything except "component" and "root" props above):
          text: "something"
          // ...more.props...
        })
        .onOk(() => {
          console.log("OK");
        })
        .onCancel(() => {
          console.log("Cancel");
        })
        .onDismiss(() => {
          console.log("Called on OK or Cancel");
        });
    }
  }
};
</script>

<style scoped>
</style>
